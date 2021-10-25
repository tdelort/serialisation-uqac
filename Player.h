#pragma once

#include <Serializer.h>
#include <Deserializer.h>
#include <IntCompressor.h>
#include <FloatCompressor.h>
#include <VectCompressor.h>
#include <QuatCompressor.h>
#include "framework.h"

#include <string>

namespace uqac::game
{
    struct Player
    {
        Vector3D m_position; // X Y entre -500 et 500 et Z entre 0 et 100
        Quaternion m_rotation;
        Vector3D m_taille; 
        int m_vie; // vie entre 0 et 300
        int m_armure; // armure entre 0 et 50
        float m_argent; // argent entre -99 999,99 et 99 999,99
        std::string m_nom; // nom de max 128 char

    };

    std::pair<char*,int> Write(Player p)
    {
        uqac::serialisation::Serializer s(6);

        uqac::serialisation::IntCompressor vieComp(0, 300);
        uqac::serialisation::IntCompressor armorComp(0, 50);
        uqac::serialisation::FloatCompressor moneyComp(-99999.99, 99999.99, 3);
        uqac::serialisation::VectCompressor positionComp({-500, -500, 0}, {500, 500, 100}, {3, 3, 3});
        uqac::serialisation::VectCompressor tailleComp({0, 0, 0}, {10, 10, 20}, {3, 3, 3});
        uqac::serialisation::QuatCompressor rotationComp;

        vieComp.Compress(&s, p.m_vie);
        armorComp.Compress(&s, p.m_armure);
        moneyComp.Compress(&s, p.m_argent);
        positionComp.Compress(&s, p.m_position);
        tailleComp.Compress(&s, p.m_taille);
        rotationComp.Compress(&s, p.m_rotation);

        return std::make_pair(s.GetBuffer(), s.GetBufferSize());
    }

    Player Read(char* buffer, int size)
    {
        uqac::serialisation::Deserializer ds(buffer, size);

        uqac::serialisation::IntCompressor vieComp(0, 300);
        uqac::serialisation::IntCompressor armorComp(0, 50);
        uqac::serialisation::FloatCompressor moneyComp(-99999.99, 99999.99, 3);
        uqac::serialisation::VectCompressor positionComp({-500, -500, 0}, {500, 500, 100}, {3, 3, 3});
        uqac::serialisation::VectCompressor tailleComp({0, 0, 0}, {10, 10, 20}, {3, 3, 3});
        uqac::serialisation::QuatCompressor rotationComp;

        Player p;

        p.m_vie = vieComp.Decompress(&ds);
        p.m_armure = armorComp.Decompress(&ds);
        p.m_argent = moneyComp.Decompress(&ds);
        p.m_position = positionComp.Decompress(&ds);
        p.m_taille = tailleComp.Decompress(&ds);
        p.m_rotation = rotationComp.Decompress(&ds);

        return p;
    }

}