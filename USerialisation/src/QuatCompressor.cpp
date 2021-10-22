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
		int min = 0;
		int value_x = static_cast<int> ((val.x - m_min) * precision);
		int value_y = static_cast<int> ((val.y - m_min) * precision);
		int value_w = static_cast<int> ((val.w - m_min) * precision);
		uint32_t res = (ignore << 30) | (value_x << 20) | (value_y << 10) | (value_w);
		s.Serialize(res);
	}
	else
	{
		ignore = 0b11;
		int min = 0;
		int value_x = static_cast<int> ((val.x - m_min) * precision);
		int value_y = static_cast<int> ((val.y - m_min) * precision);
		int value_z = static_cast<int> ((val.z - m_min) * precision);
		uint32_t res = (ignore << 30) | (value_x << 20) | (value_y << 10) | (value_z);
		s.Serialize(res);
	}
}