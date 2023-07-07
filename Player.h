#pragma once
#include "Engine/GameObject.h"

class Fbx;

class Player :
    public GameObject
{
    Fbx* pFbx;
};

