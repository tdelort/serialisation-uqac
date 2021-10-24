#include "FloatCompressor.h"
#include "Serializer.h"
#include "framework.h"

FloatCompressor::FloatCompressor(float min, float max, int precision) 
{
	m_min = min;
	m_max = max;
    m_maxRange = maxRange(m_min, m_max, precision);
	m_precision = std::pow(10,precision);
}

FloatCompressor::~FloatCompressor()
{
	//plus tard
}

void FloatCompressor::Compress(Serializer s, float val)
{
	int min = 0;
	int value = static_cast<int> ((val - m_min) * m_precision);
	int comp = nbOctet(m_maxRange);
    switch (comp)
    {
        case 1:
        {
            s.Serialize(static_cast<uint8_t>(value));
        }
        case 2:
        {
            s.Serialize(static_cast<uint16_t>(value));
        }
        case 3:
        {
            s.Serialize(static_cast<uint32_t>(value));
        }
        case 4:
        {
            s.Serialize(static_cast<uint64_t>(value));
        }
    }
}