#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Bullet>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
}

void PlayScene::Update()
{
	static float time = 0.0f;
	ot_.position_ = { 0.0f,0.0f,0.0f };
	ot_.scale_ = { 0.5f,0.5f,0.5f };
	//ot_.rotate_ = { 0.0f,0.0f,90.0f };

	//ot_.rotate_.y += time;
	time += 0.01f;
	ot_.position_.x += 6.0f * cos(time);
	ot_.position_.y += 6.0f * sin(time)/3;
	//ot_.position_.z += 1.0f * tan(time);
	//ot_.rotate_.z += 1000.0f;
	//ot_.rotate_.x += 1000.0f;
}

void PlayScene::Draw()
{	
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
