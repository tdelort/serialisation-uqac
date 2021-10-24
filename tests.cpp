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
    Serializer s(4);

    int vie = 12;
    float money = -64008.09;
    Vector3D position = {12.512f, -40.0f, 1.0f};

    std::cout << "vie : " << vie << std::endl;
    std::cout << "money : " << money << std::endl;
    std::cout << "pos : " << position.x << " " << position.y << " " << position.z << std::endl << std::endl;
    // Euler(45, 180, 65) = Quat(0.4964001, 0.7791921, 0.3227519, -0.2056157)
    Quaternion rotation = {0.4964001f, 0.7791921f, 0.3227519f, -0.2056157f};

    IntCompressor vieComp(0, 300);
    FloatCompressor moneyComp(-99999.99, 99999.99, 3);
    VectCompressor positionComp({-500, -500, 0}, {500, 500, 100}, {3, 3, 3});
    QuatCompressor rotationComp;

    vieComp.Compress(&s, vie);
    moneyComp.Compress(&s, 12.512f);
    positionComp.Compress(&s, position);
    rotationComp.Compress(&s, rotation);

    char* buffer = s.GetBuffer();
    unsigned int bufferSize = s.GetBufferSize();
    // Send s through Socket

    for(int i = 0; i < bufferSize; i++)
        std::cout << (buffer[i] ? buffer[i] : '.');
    std::cout << std::endl << std::endl;

    Deserializer ds(buffer, bufferSize);

    int n_vie = vieComp.Decompress(&ds);
    float n_money = moneyComp.Decompress(&ds);
    Vector3D n_position = positionComp.Decompress(&ds);
    Quaternion n_rotation = rotationComp.Decompress(&ds);

    std::cout << "vie : " << n_vie << std::endl;
    std::cout << "money : " << n_money << std::endl;
    std::cout << "pos : " << n_position.x << " " << n_position.y << " " << n_position.z << std::endl;
    std::cout << "rot : " << n_rotation.x << " " << n_rotation.y << " " << n_rotation.z << " " << n_rotation.w << std::endl;

    return 0;
}