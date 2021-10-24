#include "QuatCompressor.h"

#include "Serializer.h"
#include "Deserializer.h"

#include <algorithm>

QuatCompressor::QuatCompressor()
{
	m_min = -0.707;
	m_max = 0.707;
	m_precision = 1000 * 1414 / 1023;
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
	Quaternion q;
	uint32_t value = ds->Deserialize<uint32_t>();
	int ignore = (value >> 30);
	if (ignore == 00) 
	{
		float z = value & 0x3FF;
		float y = (value >> 10) & 0x3FF;
		float w = (value >> 20) & 0x3FF;
		float x = 1 - y * y - z * z - w * w;
		q.x = (x / m_precision) + m_min;
		q.y = (y / m_precision) + m_min;
		q.z = (z / m_precision) + m_min;
		q.w = (w / m_precision) + m_min;
	}
	else if (ignore == 01)
	{
		float z = value & 0x3FF;
		float w = (value >> 10) & 0x3FF;
		float x = (value >> 20) & 0x3FF;
		float y = 1 - x * x - z * z - w * w;
		q.x = (x / m_precision) + m_min;
		q.y = (y / m_precision) + m_min;
		q.z = (z / m_precision) + m_min;
		q.w = (w / m_precision) + m_min;
	}
	else if (ignore == 10)
	{
		float w = value & 0x3FF;
		float y = (value >> 10) & 0x3FF;
		float x = (value >> 20) & 0x3FF;
		float z = 1 - x * x - y * y - w * w;
		q.x = (x / m_precision) + m_min;
		q.y = (y / m_precision) + m_min;
		q.z = (z / m_precision) + m_min;
		q.w = (w / m_precision) + m_min;
	}
	else
	{
		float z = value & 0x3FF;
		float y = (value >> 10) & 0x3FF;
		float x = (value >> 20) & 0x3FF;
		float w = 1 - x * x - z * z - z * z;
		q.x = (x / m_precision) + m_min;
		q.y = (y / m_precision) + m_min;
		q.z = (z / m_precision) + m_min;
		q.w = (w / m_precision) + m_min;
	}
	return q; // Normal que ça râle, j'y ai pas encore touché
}