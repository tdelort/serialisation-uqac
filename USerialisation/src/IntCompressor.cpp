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

        }
        case 2 :
        {

        }
        case 3 :
        {

        }
        case 4 :
        {

        }
    }
}