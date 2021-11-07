#include <Serializer.h>
#include <Deserializer.h>
#include <IntCompressor.h>
#include <FloatCompressor.h>
#include <VectCompressor.h>
#include <QuatCompressor.h>
#include <framework.h>

#include <iostream>

int main()
{
    uqac::serialisation::Serializer s;
    s.Serialize<uint32_t>((uint32_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;
    s.Serialize<uint8_t>((uint8_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;
    s.Serialize<uint8_t>((uint8_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;
    s.Serialize<uint8_t>((uint8_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;
    s.Serialize<uint8_t>((uint8_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;
    s.Serialize<uint32_t>((uint32_t)1);
    std::cout << "size : " << s.GetBufferSize() << std::endl;

    std::cout << "buffer : ";
    char* buffer = s.GetBuffer();
    for(int i = 0; i < s.GetBufferSize(); i++)
    {
        char c = (int)buffer[i];
        std::cout << (c ? c : '.');
    }
    std::cout << std::endl;


    uqac::serialisation::Deserializer ds(s.GetBuffer(), s.GetBufferSize());
    uint32_t i = ds.Deserialize<uint32_t>();
    uint8_t i2 = ds.Deserialize<uint8_t>();
    uint8_t i3 = ds.Deserialize<uint8_t>();
    uint8_t i4 = ds.Deserialize<uint8_t>();
    uint8_t i5 = ds.Deserialize<uint8_t>();
    uint32_t i6 = ds.Deserialize<uint32_t>();

    std::cout << "test : " << (int)i << std::endl;
    std::cout << "test : " << (int)i2 << std::endl;
    std::cout << "test : " << (int)i3 << std::endl;
    std::cout << "test : " << (int)i4 << std::endl;
    std::cout << "test : " << (int)i5 << std::endl;
    std::cout << "test : " << (int)i6 << std::endl;

    return 0;
}