#pragma once
#include "Engine/GameObject.h"

class Fbx;

class Childoden :
    public GameObject
{
    int hModel_;
    Fbx* pFbx;
public:
    Childoden(GameObject* parent);
    ~Childoden();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

