#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

namespace {
	Player* player_ = nullptr;
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	for (int i = 0;i < 15;i++) {
		float posx = (((float)rand() / RAND_MAX) * 20.0f) - 10.0f;
		Enemy* e = Instantiate<Enemy>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
		e->SetPosiition(posx*10.0f, 0.0f, 20.0f);
	}
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る

}

void PlayScene::Update()
{
	if (FindObject("Enemy")==nullptr) {
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
