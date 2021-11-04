#pragma once

#include "Compressor.h"
#include "FloatCompressor.h"
#include "framework.h"

#include <optional>

namespace uqac::serialisation
{

    class VectCompressor : public Compressor<Vector3D>
    {
    private:
        FloatCompressor m_compx, m_compy, m_compz;
    public:
        VectCompressor(Vector3D min, Vector3D max, Vector3D precision);
        ~VectCompressor();

        void Compress(Serializer* s, Vector3D val) override;
        Vector3D Decompress(Deserializer* ds) override;
    };
}