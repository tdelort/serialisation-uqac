#include "FloatCompressor.h"
#include "Serializer.h"
#include "Deserializer.h"
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

float FloatCompressor::Decompress(Deserializer ds)
{
    float value;
    switch (nbOctet(m_maxRange))
    {
        case 1 :
        {
            uint8_t recup = ds.Deserialize<uint8_t>();
            value = static_cast<float>(recup);
            break;
        }
        case 2 :
        {
            uint16_t recup = ds.Deserialize<uint16_t>();
            value = static_cast<float>(recup);
            break;
        }
        case 3 :
        {
            uint32_t recup = ds.Deserialize<uint32_t>();
            value = static_cast<float>(recup);
            break;
        }
        case 4 :
        {
            uint64_t recup = ds.Deserialize<uint64_t>();
            value = static_cast<float>(recup);
            break;
        }
    }
    return value/m_precision + m_min;
}