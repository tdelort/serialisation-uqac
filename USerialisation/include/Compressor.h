#pragma once

class Serializer;

template<typename T>
class Compressor
{
public:
    virtual void Compress(Serializer s, T val) = 0;
    virtual void Decompress(Serializer s, T val) = 0;
};