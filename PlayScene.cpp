#include "PlayScene.h"
#include "Engine/Fbx.h"
#include "Player.h"

PlayScene::PlayScene(GameObject* parent)
{
}

void PlayScene::Initialize()
{
	//Player* pPlayer;
	//pPlayer = new Player(this); //プレイヤーの親は自分(PlayaScene)
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer); //PlaySceneの子として、プレイヤーを登録
	Instantiate<PlayScene>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}