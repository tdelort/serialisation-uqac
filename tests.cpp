#include <Serializer.h>

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

    return 0;
}