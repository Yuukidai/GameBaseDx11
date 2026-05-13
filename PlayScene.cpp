#include "PlayScene.h"
#include "Engine/Model.h" //\\でもオッケー


#include "Engine/Direct3D.h"
#include "Engine/Camera.h"
#include <DirectXMath.h>

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)//なんで-1かというと、モデルは0以上の番号。読み込んでそれでも番号が変わっていない場合それはエラーになる

{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);//読み込みに失敗したらすぐエラーになって落ちるのはゲーム的にはよくないけど開発中はおｋ
	
}

void PlayScene::Update()
{
	static float time = 0.0f;

	ot_.position_ = { 0.0f, 0.0f, 10.0f };
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	//ot_.rotate_= {0.0f,0.0f,0.0f};

	//ot_.rotate_.y = time;
	time += 0.025f;
	ot_.position_.x = 6.0f * sin(time);
	//float posx = 6.0 * sin(0.2f * time);
	//float posy = cos(3.0f * time);
	//ot_.position_.x = posx;
	//ot_.position_.y = posy;

	
}

void PlayScene::Draw()
{	
	Model::SetTransform(hModel_ , ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
