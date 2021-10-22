#include <Serializer.h>

#include <iostream>

int main()
{
    Serializer s(4);

    s.Serialize((uint8_t)12);
    s.Serialize((uint16_t)12);
    s.Serialize((uint32_t)12);
    s.Serialize((uint64_t)12);

    return 0;
}