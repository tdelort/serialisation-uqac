#pragma once

#include "Compressor.h"
#include "framework.h"

class QuatCompressor : public Compressor<Quaternion>
{
private:
    float m_min, m_max;
    int m_precision;
public:
    QuatCompressor(float min, float max, int precision);
    ~QuatCompressor();

    void operator()(Serializer s, Quaternion val) override;
};
