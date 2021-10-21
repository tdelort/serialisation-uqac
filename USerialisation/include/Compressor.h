#pragma once

class Serializer;

template<typename T>
class Compressor
{
public:
    virtual char* operator()(Serializer s, T val) = 0;
};

/*

Compressor c;

char* data = c(s, val);


*/
