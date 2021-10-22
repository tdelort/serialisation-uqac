#pragma once

#include <vector>

class Serializer
{
public:
    Serializer(unsigned int size = 0);
    ~Serializer();

    template<typename T>
    void Serialize(T val);

    //Getters
private:
    std::vector<char> m_container;
    unsigned int m_size;

    void Write(const char* data, unsigned int size);
};
