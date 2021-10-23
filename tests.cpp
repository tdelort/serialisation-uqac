#include <Serializer.h>
#include <Deserializer.h>
#include <framework.h>

#include <iostream>

int main()
{
    Serializer s(4);

    s.Serialize((uint8_t)0x61);
    s.Serialize((uint16_t)0x6162);
    s.Serialize((uint32_t)0x61626364);
    s.Serialize((uint64_t)0X6162636465666768);

    std::vector<char> buffer = s.GetBuffer();

    for(char c : buffer)
        std::cout << (c ? c : '.');
    std::cout << std::endl;

    Deserializer ds(buffer.data(), buffer.size());
    uint8_t a = ds.Deserialize<uint8_t>();
    uint16_t b = ds.Deserialize<uint16_t>();
    uint32_t c = ds.Deserialize<uint32_t>();
    uint64_t d = ds.Deserialize<uint64_t>();

    std::cout << std::hex << (int)a << std::endl;
    std::cout << std::hex << b << std::endl;
    std::cout << std::hex << c << std::endl;
    std::cout << std::hex << d << std::endl;

    return 0;
}