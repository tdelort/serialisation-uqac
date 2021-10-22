#pragma once

#include "Compressor.h"

class IntCompressor : public Compressor<int>
{
private:
    int m_min, m_max;
public:
    IntCompressor(int min, int max);
    ~IntCompressor();

    char* operator()(Serializer s, int val) override;
};

