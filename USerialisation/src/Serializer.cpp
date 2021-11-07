#include "Serializer.h"

#include <iostream>

namespace uqac::serialisation
{

    Serializer::Serializer(unsigned int size)
        : m_size(0), m_container(size)
    { }

    Serializer::~Serializer()
    { }

    template<typename T>
    void Serializer::Serialize(T val)
    {
        unsigned int nbOctet = sizeof(T);
        if(nbOctet + m_size > m_container.size())
            m_container.resize(m_size + nbOctet);

        memcpy(m_container.data() + m_size, &val, nbOctet);
        m_size += nbOctet;
    }

    // allows to define Serialize in the .cpp and restrains the types that T can be
    template void Serializer::Serialize<uint8_t>(uint8_t val);
    template void Serializer::Serialize<uint16_t>(uint16_t val);
    template void Serializer::Serialize<uint32_t>(uint32_t val);
    template void Serializer::Serialize<uint64_t>(uint64_t val);

    char* Serializer::GetBuffer()
    {
        return m_container.data();
    }

    unsigned int Serializer::GetBufferSize()
    {
        return m_size;
    }
}