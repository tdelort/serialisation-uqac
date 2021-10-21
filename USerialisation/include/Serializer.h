#pragma once

class Serializer
{
public:
    Serializer();
    Serializer(unsigned int size);
    ~Serializer();


    template<typename T>
    char* Compressor(T t);

    //template magique serialize

    //Getters
private:
    // A container
    // A position (iterator on the container)
};