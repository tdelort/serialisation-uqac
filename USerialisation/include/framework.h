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

inline int maxRange(int min, int max, int prec = 0) {
    return (max - min) * std::pow(10, prec);
}

inline int nbOctet(int mr) {
    return 1 + (mr > UINT8_MAX) + (mr > UINT16_MAX) + (mr > UINT32_MAX);
}