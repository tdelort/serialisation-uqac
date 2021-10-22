#include "QuatCompressor.h"

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

void QuatCompressor::operator()(Serializer s, Quaternion val) override
{
	int max_val = std::max(val.x, val.y, val.z, val.w);
	int ignore;
	if (max_val == val.w) 
	{
		ignore = 0b10;
		uint32_t res = quatOctet(val.x, val.y, val.w, ignore, m_precision, m_min);
		s.Serialize(res);
	}
	else
	{
		ignore = 0b11;
		uint32_t res = quatOctet(val.x, val.y, val.z, ignore, m_precision, m_min);
		s.Serialize(res);
	}
}