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

    void Compress(Serializer s, int val) override;
    int Decompress(Deserializer ds) override;
};

