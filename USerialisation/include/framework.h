#pragma once 

#include <cmath>

struct Vector3D 
{
    float x;
    float y;
    float z;
};

struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
};

inline int maxRange(int min, int max, int prec = 0) 
{
    return (max - min) * std::pow(10, prec);
}

inline int nbOctet(int mr) 
{
    return ((1 << 8) < mr) + ((1 << 16) < mr) + ((1 << 32) < mr) + ((1 << 64) < mr);
}

inline int quatOctet(int valx, int valy, int valz, int start, int precision, int min) 
{
    return ((start << 30) | 
        (static_cast<int> ((valx - min) * precision) << 20) | 
        (static_cast<int> ((valy - min) * precision) << 10) | 
        (static_cast<int> ((valz - min) * precision)));
}