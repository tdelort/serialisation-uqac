#include <framework.h>
#include "Player.h"

#include <iostream>

int main()
{
    Player p;
    p.m_nom = "Jean";
    p.m_vie = 300;
    p.m_armure = 0;
    p.m_argent = 100;
    p.m_position = {10, 0, 0};
    p.m_taille = {1, 0.5, 2};
    p.m_rotation = {0.4964001f, 0.7791921f, 0.3227519f, -0.2056157f};

    std::pair<char*, int> buffer = Write(p);

    Player p2 = Read(buffer.first, buffer.second);
    
    std::cout << "vie : " << p.m_vie << std::endl;
    std::cout << "money : " << p.m_argent << std::endl;
    std::cout << "pos : " << p.m_position.x << " " << p.m_position.y << " " << p.m_position.z << std::endl;
    std::cout << "rot : " << p.m_rotation.x << " " << p.m_rotation.y << " " << p.m_rotation.z << " " << p.m_rotation.w << std::endl;

}