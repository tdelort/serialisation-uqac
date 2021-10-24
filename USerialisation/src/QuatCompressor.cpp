#include "QuatCompressor.h"

#include "Serializer.h"
#include "Deserializer.h"

#include <algorithm>

QuatCompressor::QuatCompressor(float min, float max, int precision)
{
	m_min = min;
	m_max = max;
	m_precision = precision;
}

QuatCompressor::~QuatCompressor()
{
	//plus tard
}

void QuatCompressor::Compress(Serializer* s, Quaternion val)
{
	int max_val = std::max({val.x, val.y, val.z, val.w});
	int ignore;
	if (max_val == val.w) 
	{
		ignore = 0b11;
		uint32_t res = quatOctet(val.x, val.y, val.z, ignore, m_precision, m_min);
		s->Serialize(res);
	}
	else if (max_val == val.z)
	{
		ignore = 0b10;
		uint32_t res = quatOctet(val.x, val.y, val.w, ignore, m_precision, m_min);
		s->Serialize(res);		
	}
	else if (max_val == val.y)
	{
		ignore = 0b01;
		uint32_t res = quatOctet(val.x, val.w, val.z, ignore, m_precision, m_min);
		s->Serialize(res);
	}
	else
	{
		ignore = 0b00;
		uint32_t res = quatOctet(val.w, val.y, val.z, ignore, m_precision, m_min);
		s->Serialize(res);
	}
}

Quaternion QuatCompressor::Decompress(Deserializer* ds)
{
	uint32_t value = ds->Deserialize<uint32_t>();
	int ignore = (value >> 30);
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
	Quaternion q;
	if (ignore == 00) 
	{
		z = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		w = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.x = 1 - q.y * q.y - q.z * q.z - q.w * q.w;
	}
	else if (ignore == 01)
	{
		z = value & 0x3FF;
		w = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.y = 1 - q.x * q.x - q.z * q.z - q.w * q.w;
	}
	else if (ignore == 10)
	{
		w = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.z = 1 - q.y * q.y - q.x * q.x - q.w * q.w;
	}
	else
	{
		z = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.w = 1 - q.y * q.y - q.z * q.z - q.x * q.x;
	}
	return q; // Normal que ça râle, j'y ai pas encore touché
}