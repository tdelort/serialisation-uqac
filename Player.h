#pragma once

#include "framework.h"

class Player
{
private:
    Vector3D position; // X Y entre -500 et 500 et Z entre 0 et 100
    Quaternion rotation;
    Vector3D taille; 
    int vie; // vie entre 0 et 300
    int armure; // armure entre 0 et 50
    float argent; // argent entre -99 999,99 et 99 999,99
    std::string nom; // nom de max 128 car
}