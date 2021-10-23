#pragma once

class Deserializer
{
public:
    Deserializer(const char *buffer, unsigned int size);
    ~Deserializer();

    template<typename T>
    T Deserialize();

private:
    const char *m_buffer;
    unsigned int m_size, m_pos;
};