#include "Serializer.h"

Serializer::Serializer(unsigned int size)
    : m_size(0), m_container(size)
{ }

Serializer::~Serializer()
{

}

template<typename T>
void Serializer::Serialize(T val)
{
    unsigned int nbOctet = sizeof(val);
    if(nbOctet + m_size > m_container.capacity())
        m_container.resize(m_container.capacity() + nbOctet);

    Write((char*)&val, nbOctet);
}

// allows to define Serialize in the .cpp and restrains the types that T can be
template void Serializer::Serialize<uint8_t>(uint8_t val);
template void Serializer::Serialize<uint16_t>(uint16_t val);
template void Serializer::Serialize<uint32_t>(uint32_t val);
template void Serializer::Serialize<uint64_t>(uint64_t val);

std::vector<char> Serializer::GetBuffer()
{
    return m_container;
}

void Serializer::Write(const char* data, unsigned int size)
{
    memcpy(m_container.data() + m_size, data, size);
    m_size += size;
}