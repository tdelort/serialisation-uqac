#include "IntCompressor.h"
#include "framework.h"

IntCompressor::IntCompressor(int min, int max)
{
    m_min = min;
    m_max = max;
    m_maxRange = maxRange(min, max);
    
}

IntCompressor::~IntCompressor()
{

}

void IntCompressor::operator()(Serializer s, int val)
{
    int scaledInt = val - m_min;
    int nbOctet = nbOctet(m_maxRange);
    switch (nbOctet)
    {
        case 1 :
        {
            uint8_t res = static_cast<uint8_t>(scaledInt);
            Serializer.Serialize(res);
            break;
        }
        case 2 :
        {
            uint16_t res = static_cast<uint16_t>(scaledInt);
            Serializer.Serialize(res);
            break;
        }
        case 3 :
        {
            uint32_t res = static_cast<uint32_t>(scaledInt);
            Serializer.Serialize(res);
            break;
        }
        case 4 :
        {
            uint64_t res = static_cast<uint64_t>(scaledInt);
            Serializer.Serialize(res);
            break;
        }
    }

}