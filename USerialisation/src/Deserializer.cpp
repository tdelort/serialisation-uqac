#include "Deserializer.h"

#include <iostream>

Deserializer::Deserializer(const char *buffer, unsigned int size)
    : m_buffer(buffer), m_size(size), m_pos(0)
{ }

Deserializer::~Deserializer()
{ }

template<typename T>
T Deserializer::Deserialize()
{
    unsigned int nbOctet = sizeof(T);
    if(m_pos + nbOctet > m_size)
    {
        std::cerr << "Deserialization::Deserialize : Container end reached" << std::endl;
        return 0;
    }

    T val = *(T*)(m_buffer + m_pos);
    m_pos += nbOctet;
    return val;
}

template uint8_t Deserializer::Deserialize<uint8_t>();
template uint16_t Deserializer::Deserialize<uint16_t>();
template uint32_t Deserializer::Deserialize<uint32_t>();
template uint64_t Deserializer::Deserialize<uint64_t>();