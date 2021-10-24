#pragma once

class Serializer;
class Deserializer;

template<typename T>
class Compressor
{
public:
    virtual void Compress(Serializer* s, T val) = 0;
    virtual T Decompress(Deserializer* ds) = 0;
};