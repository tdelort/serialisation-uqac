#include "QuatCompressor.h"

#include "Serializer.h"
#include "Deserializer.h"

#include <iostream>
#include <algorithm>

QuatCompressor::QuatCompressor()
{
	m_min = -0.707;
	m_max = 0.707;
	//723 = 1000 * 1023 / 1414
	m_precision = 723;
}

QuatCompressor::~QuatCompressor()
{
	//plus tard
}

void QuatCompressor::Compress(Serializer* s, Quaternion val)
{
	float max_val = std::max({val.x, val.y, val.z, val.w});
	int ignore;
	if (max_val == val.w) 
	{
		ignore = 0b11;
		uint32_t res = quatOctet(val.x, val.y, val.z, ignore, m_precision, m_min);
		std::cout << res << " q" << std::endl;
		s->Serialize(res);
	}
	else if (max_val == val.z)
	{
		ignore = 0b10;
		uint32_t res = quatOctet(val.x, val.y, val.w, ignore, m_precision, m_min);
		std::cout << res << " q" << std::endl;
		s->Serialize(res);		
	}
	else if (max_val == val.y)
	{
		ignore = 0b01;
		uint32_t res = quatOctet(val.x, val.w, val.z, ignore, m_precision, m_min);
		std::cout << res << " q" << std::endl;
		s->Serialize(res);
	}
	else
	{
		ignore = 0b00;
		uint32_t res = quatOctet(val.w, val.y, val.z, ignore, m_precision, m_min);
		std::cout << res << " q" << std::endl;
		s->Serialize(res);
	}
}

Quaternion QuatCompressor::Decompress(Deserializer* ds)
{
	uint32_t value = ds->Deserialize<uint32_t>();
	int ignore = (value >> 30);
	std::cout << ignore << " i" << std::endl;
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
	Quaternion q;
	if (ignore == 0b00) 
	{
		z = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		w = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.x = std::sqrt(1.0f - q.y * q.y - q.z * q.z - q.w * q.w);
	}
	else if (ignore == 0b01)
	{
		z = value & 0x3FF;
		w = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.y = std::sqrt(1.0f - q.x * q.x - q.z * q.z - q.w * q.w);
	}
	else if (ignore == 0b10)
	{
		w = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.z = std::sqrt(1.0f - q.y * q.y - q.x * q.x - q.w * q.w);
	}
	else
	{
		z = value & 0x3FF;
		y = (value >> 10) & 0x3FF;
		x = (value >> 20) & 0x3FF;
		q = result(x, y, z, w, m_precision, m_min);
		q.w = std::sqrt(1.0f - q.y * q.y - q.z * q.z - q.x * q.x);
	}
	return q; // Normal que ça râle, j'y ai pas encore touché
}