#include "FloatCompressor.h"
#include "framework.h"

FloatCompressor::FloatCompressor(float min, float max, int precision) 
{
	m_min = min;
	m_max = max;
	m_precision = precision;
}

FloatCompressor::~FloatCompressor()
{
	//plus tard
}

void FloatCompressor::operator()(Serializer s, float val) override
{
	int min = 0;
	int max = maxRange(m_min, m_max, m_precision);
	int value = static_cast<int> ((val - m_min) * precision);
	int comp = nbOctet(max);
    switch (comp)
    {
        case 1:
        {
            s.Serialize(static_cast<uint8_t> value);
        }
        case 2:
        {
            s.Serialize(static_cast<uint16_t> value);
        }
        case 3:
        {
            s.Serialize(static_cast<uint32_t> value);
        }
        case 4:
        {
            s.Serialize(static_cast<uint64_t> value);
        }
    }
}