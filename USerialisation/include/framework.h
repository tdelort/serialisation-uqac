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

inline uint32_t quatOctet(float valx, float valy, float valz, int start, int precision, float min) 
{
    int a = (start & 0b11);
    int b = (static_cast<int>((valx - min) * precision) & 0x3FF);
    int c = (static_cast<int>((valy - min) * precision) & 0x3FF);
    int d = (static_cast<int>((valz - min) * precision) & 0x3FF);
    return (a << 30) | (b << 20) | (c << 10) | d;
}

inline Quaternion result(float valx, float valy, float valz, float valw, int precision, float min)
{
    return {
        (valx / precision) + min,
        (valy / precision) + min,
        (valz / precision) + min,
        (valw / precision) + min
    };
}