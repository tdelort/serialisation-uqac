#pragma once 

#include <cmath>
#include <stdint.h>

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
    return 1 + (mr > UINT8_MAX) + (mr > UINT16_MAX) + (mr > UINT32_MAX);
}

inline int quatOctet(int valx, int valy, int valz, int start, int precision, int min) 
{
    return ((start << 30) | 
        (static_cast<int> ((valx - min) * precision) << 20) | 
        (static_cast<int> ((valy - min) * precision) << 10) | 
        (static_cast<int> ((valz - min) * precision)));
}