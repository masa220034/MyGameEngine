#include "Player.h"
#include "Engine/Fbx.h"
#include "Childoden.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), pFbx(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/Oden.fbx");
	this->transform_.scale_.x = 0.5;
	this->transform_.scale_.y = 0.5;
	this->transform_.scale_.z = 0.5;
	Instantiate<Childoden>(this);
	GameObject* pCO2 = Instantiate<Childoden>(this);
	pCO2->transform_.position_
}

void Player::Update()
{
	transform_.rotate_.y++;
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.1f;
	}
}

void Player::Draw()
{
	pFbx->Draw(transform_);
}

void Player::Release()
{
	pFbx->Release();
	delete pFbx;
}