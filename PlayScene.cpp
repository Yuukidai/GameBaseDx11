#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

namespace {
	Player* player_ = nullptr;
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{

	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Bullet>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (Input::IsKey(DIK_I)) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

}

void PlayScene::Draw()
{	

}

void PlayScene::Release()
{
}
