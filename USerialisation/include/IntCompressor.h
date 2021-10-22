#pragma once

#include "Compressor.h"

class IntCompressor : public Compressor<int>
{
private:
    int m_min, m_max;
    int m_maxRange;
public:
    IntCompressor(int min, int max);
    ~IntCompressor();

    void Comrpess(Serializer s, int val) override;
    void Decomrpess(Serializer s, int val) override;
};

