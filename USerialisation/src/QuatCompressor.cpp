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

void QuatCompressor::Compress(Serializer s, Quaternion val)
{
	int max_val = std::max({val.x, val.y, val.z, val.w});
	int ignore;
	if (max_val == val.w) 
	{
		ignore = 0b11;
		uint32_t res = quatOctet(val.x, val.y, val.z, ignore, m_precision, m_min);
		s.Serialize(res);
	}
	else if (max_val == val.z)
	{
		ignore = 0b10;
		uint32_t res = quatOctet(val.x, val.y, val.w, ignore, m_precision, m_min);
		s.Serialize(res);		
	}
	else if (max_val == val.y)
	{
		ignore = 0b01;
		uint32_t res = quatOctet(val.x, val.w, val.z, ignore, m_precision, m_min);
		s.Serialize(res);
	}
	else
	{
		ignore = 0b00;
		uint32_t res = quatOctet(val.w, val.y, val.z, ignore, m_precision, m_min);
		s.Serialize(res);
	}
}

Quaternion QuatCompressor::Decompress(Deserializer ds)
{
	Quaternion q;
	return q; // Normal que ça râle, j'y ai pas encore touché
}