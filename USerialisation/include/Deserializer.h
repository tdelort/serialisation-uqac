#pragma once

class Deserializer
{
public:
    Deserializer(char *buffer, unsigned int size);
    ~Deserializer();

    template<typename T>
    T Read();

private:
    char *m_buffer;
};