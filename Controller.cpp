#include "Controller.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Controller::Controller(GameObject* parent)
    :GameObject(parent, "Controller")
{
    transform_.position_.x = 7.0f;
    transform_.position_.z = 7.0f;

    transform_.rotate_.x = 45.0f;
}

//�f�X�g���N�^
Controller::~Controller()
{
}

//������
void Controller::Initialize()
{
}

//�X�V
void Controller::Update()
{
    //����]
    if (Input::IsKey(DIK_LEFT))
    {
        transform_.rotate_.y -= 1.0f;
    }

    //�E��]
    if (Input::IsKey(DIK_RIGHT))
    {
        transform_.rotate_.y += 1.0f;
    }

    //transform_.rotate_.y�̒l�ɍ��킹�Ăx����]������s��
    XMMATRIX mRotateY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));

    if (Input::IsKey(DIK_UP))
    {
        transform_.rotate_.x += 1.0f;
        if (transform_.rotate_.x > 89)
        {
            transform_.rotate_.x = 89;
        }
    }

    if (Input::IsKey(DIK_DOWN))
    {
        transform_.rotate_.x -= 1.0f;
        if (transform_.rotate_.x < 0)
        {
            transform_.rotate_.x = 0;
        }
    }

    XMMATRIX mRotateX = XMMatrixRotationX(XMConvertToRadians(transform_.rotate_.x));

    //���݈ʒu���x�N�g���ɂ��Ă���
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

    //�O��ړ��x�N�g��
    XMVECTOR frontMove = XMVectorSet(0, 0, 0.1f,0);              //��������XMFLOAT3�\���̂�p�ӂ�
    frontMove = XMVector3TransformCoord(frontMove, mRotateY);    //��Ԃ̌����ɍ��킹�ĉ�]


    if (Input::IsKey(DIK_W))
    {
        vPos += frontMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }
    if (Input::IsKey(DIK_S))
    {
        vPos -= frontMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }

    //���E�ړ��x�N�g��
    XMVECTOR rightMove = XMVectorSet(0.1f, 0, 0, 0);             //�E������XMFLOAT3�\���̂�p�ӂ�
    rightMove = XMVector3TransformCoord(rightMove, mRotateY);    //��Ԃ̌����ɍ��킹�ĉ�]

    if (Input::IsKey(DIK_D))
    {
        vPos += rightMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }
    if (Input::IsKey(DIK_A))
    {
        vPos -= rightMove;
        XMStoreFloat3(&transform_.position_, vPos);
    }

    //�J����
    XMVECTOR vCam = XMVectorSet(0, 0, -10, 0);                   //���B��_�p��
    vCam = XMVector3TransformCoord(vCam, mRotateX * mRotateY);   //���B��_��]
    Camera::SetPosition(vPos + vCam);                            //�J�����̈ʒu�͎��B��_�̐�[(���ݒn+���B��_)
    Camera::SetTarget(XMLoadFloat3(&transform_.position_));      //�J�����̏œ_�̓v���C���[�̈ʒu
} 

//�`��
void Controller::Draw()
{
}

//�J��
void Controller::Release()
{
}