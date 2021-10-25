#include "IntCompressor.h"
#include "Serializer.h"
#include "Deserializer.h"
#include "framework.h"

namespace uqac::serialisation
{

    IntCompressor::IntCompressor(int min, int max)
    {
        m_min = min;
        m_max = max;
        m_maxRange = maxRange(min, max);
    }

    IntCompressor::~IntCompressor()
    {

    }

    void IntCompressor::Compress(Serializer* s, int val)
    {
        int scaledInt = val - m_min;
        switch (nbOctet(m_maxRange))
        {
            case 1 :
            {
                uint8_t res = static_cast<uint8_t>(scaledInt);
                s->Serialize(res);
                break;
            }
            case 2 :
            {
                uint16_t res = static_cast<uint16_t>(scaledInt);
                s->Serialize(res);
                break;
            }
            case 3 :
            {
                uint32_t res = static_cast<uint32_t>(scaledInt);
                s->Serialize(res);
                break;
            }
            case 4 :
            {
                uint64_t res = static_cast<uint64_t>(scaledInt);
                s->Serialize(res);
                break;
            }
        }
    }

    int IntCompressor::Decompress(Deserializer* ds)
    {
        int scaledInt;
        switch (nbOctet(m_maxRange))
        {
            case 1 :
            {
                uint8_t recup = ds->Deserialize<uint8_t>();
                scaledInt = static_cast<int>(recup);
                break;
            }
            case 2 :
            {
                uint16_t recup = ds->Deserialize<uint16_t>();
                scaledInt = static_cast<int>(recup);
                break;
            }
            case 3 :
            {
                uint32_t recup = ds->Deserialize<uint32_t>();
                scaledInt = static_cast<int>(recup);
                break;
            }
            case 4 :
            {
                uint64_t recup = ds->Deserialize<uint64_t>();
                scaledInt = static_cast<int>(recup);
                break;
            }
        }
        return scaledInt + m_min;
    }
}