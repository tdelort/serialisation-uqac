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
    return ((1 << 8) < mr) + ((1 << 16) < mr) + ((1 << 32) < mr) + ((1 << 64) < mr);
}