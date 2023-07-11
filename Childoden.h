#pragma once
#include "Engine/GameObject.h"

class Fbx;

class Childoden :
    public GameObject
{
    Fbx* pFbx;
public:
    Childoden(GameObject* parent);
    ~Childoden();
    void Initialize();
    void Update();
    void Draw();
    void Release();
};

