#pragma once

#include "Compressor.h"

namespace uqac::serialisation
{
    class FloatCompressor : public Compressor<float>
    {
    private:
        float m_min, m_max;
        int m_precision, m_maxRange;
    public:
        FloatCompressor(float min, float max, int precision);
        ~FloatCompressor();

        void Compress(Serializer* s, float val) override;
        float Decompress(Deserializer* ds) override;
    };

}
