#include "VectCompressor.h"

#include "Serializer.h"
#include "Deserializer.h"

#include <algorithm>

VectCompressor::VectCompressor(Vector3D min, Vector3D max, Vector3D precision)
    : m_compx(min.x, max.x, precision.x),
    m_compy(min.y, max.y, precision.y),
    m_compz(min.z, max.z, precision.z)
{ }

VectCompressor::~VectCompressor()
{
	//plus tard
}

void VectCompressor::Compress(Serializer* s, Vector3D val)
{
    m_compx.Compress(s,val.x);
    m_compy.Compress(s,val.y);
    m_compz.Compress(s,val.z);
}

Vector3D VectCompressor::Decompress(Deserializer* ds)
{
    Vector3D res;
    res.x = m_compx.Decompress(ds);
    res.y = m_compy.Decompress(ds);
    res.z = m_compz.Decompress(ds);

    return res;
}