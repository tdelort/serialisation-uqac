#pragma once

#include "Compressor.h"

class FloatCompressor : public Compressor<float>
{
private:
    float m_min, m_max;
    int m_precision;
public:
    FloatCompressor(float min, float max, int precision);
    ~FloatCompressor();

    void operator()(Serializer s, float val) override;
};
