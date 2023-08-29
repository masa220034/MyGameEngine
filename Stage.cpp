#include "Stage.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("assets/BoxDefault.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    for (int x = 0; x < 15; x++)
    {
        for (int z = 0; z < 15; z++)
        {
            Transform trans;
            trans.position_.x = x;
            trans.position_.z = z;
            Model::SetTransform(hModel_, trans);
            Model::Draw(hModel_);
        }
    }
}

//�J��
void Stage::Release()
{
}