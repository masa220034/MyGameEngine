#include "Player.h"
#include "Engine/Fbx.h"
#include "Childoden.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Assets/Oden.fbx");
	this->transform_.scale_.x = 0.5;
	this->transform_.scale_.y = 0.5;
	this->transform_.scale_.z = 0.5;
	//Instantiate<Childoden>(this);
	//GameObject* pChildOden2 = Instantiate<Childoden>(this);
	//pChildOden2->SetPosition(-2, 1, 0);
}

void Player::Update()
{
    transform_.rotate_.y++;
	//if (transform_.rotate_.y > 600)
	//{
	//	KillMe();
	//}
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.1f;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* pBullet = Instantiate<Childoden>(pParent_);
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
	//pFbx->Release();
	//delete pFbx;
}