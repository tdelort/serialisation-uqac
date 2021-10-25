#include <framework.h>
#include "Player.h"

#include <iostream>

int main()
{
    uqac::game::Player p;
    p.m_nom = "Jean";
    p.m_vie = 300;
    p.m_armure = 0;
    p.m_argent = 100;
    p.m_position = {10, 0, 0};
    p.m_taille = {1, 0.5, 2};
    p.m_rotation = {0.4964001f, 0.7791921f, 0.3227519f, -0.2056157f};

    std::pair<char*, int> buffer = uqac::game::Write(p);

    uqac::game::Player p2 = uqac::game::Read(buffer.first, buffer.second);
    
    std::cout << "vie : " << p2.m_vie << std::endl;
    std::cout << "money : " << p2.m_argent << std::endl;
    std::cout << "pos : " << p2.m_position.x << " " << p2.m_position.y << " " << p2.m_position.z << std::endl;
    std::cout << "rot : " << p2.m_rotation.x << " " << p2.m_rotation.y << " " << p2.m_rotation.z << " " << p2.m_rotation.w << std::endl;

    free(buffer.first);
}