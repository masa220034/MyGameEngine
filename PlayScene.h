#pragma once
#include "Engine/GameObject.h"

class Fbx;

class PlayScene :
    public GameObject
{
public:
    //�R���X�g���N�^
    //�����Fparent
    PlayScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

