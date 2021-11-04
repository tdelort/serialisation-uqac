#pragma once

#include <vector>

namespace uqac::serialisation
{
    class Serializer
    {
    public:
        Serializer(unsigned int size = 0);
        ~Serializer();

        template<typename T>
        void Serialize(T val);

        //Getters
        char* GetBuffer();
        unsigned int GetBufferSize();

    private:
        std::vector<char> m_container;

        unsigned int m_size;

        void Write(const char* data, unsigned int size);

    };

}


