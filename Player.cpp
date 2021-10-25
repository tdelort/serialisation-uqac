#include <Serializer.h>
#include <Deserializer.h>
#include <IntCompressor.h>
#include <FloatCompressor.h>
#include <VectCompressor.h>
#include <QuatCompressor.h>
#include "Player.h"


char* Player::Write(Player p)
{
    Serializer s(6);

    IntCompressor vieComp(0, 300);
    IntCompressor armorComp(0, 50);
    FloatCompressor moneyComp(-99999.99, 99999.99, 3);
    VectCompressor positionComp({-500, -500, 0}, {500, 500, 100}, {3, 3, 3});
    VectCompressor tailleComp({0, 0, 0}, {10, 10, 20}, {3, 3, 3});
    QuatCompressor rotationComp;

    vieComp.Compress(&s, p.m_vie);
    armorComp.Compress(&s, p.m_armure);
    moneyComp.Compress(&s, p.m_argent);
    positionComp.Compress(&s, p.m_position);
    tailleComp.Comrpess(&s, p.m_taille);
    rotationComp.Compress(&s, p.m_rotation);

    return s.GetBuffer();
}

Player Player::Read(char* buffer)
{
    Desrializer ds(buffer, 6); // Pas bonne taille

    IntCompressor vieComp(0, 300);
    IntCompressor armorComp(0, 50);
    FloatCompressor moneyComp(-99999.99, 99999.99, 3);
    VectCompressor positionComp({-500, -500, 0}, {500, 500, 100}, {3, 3, 3});
    VectCompressor tailleComp({0, 0, 0}, {10, 10, 20}, {3, 3, 3});
    QuatCompressor rotationComp;

    Player p;

    p.m_vie = vieComp.Decompress(&ds);
    p.m_armure = armorComp.Decompress(&ds);
    p.m_argent = moneyComp.Decompress(&ds);
    p.m_position = positionComp.Decompress(&ds);
    p.m_taille = tailleComp.Decomrpess(&ds);
    p.m_rotation = rotationComp.Decompress(&ds);

    return p;
}