#include "Player.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"

Player::Player(GameObject* parent)
//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("hontai.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f,-4.0f,0.0f };
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		//左に移動
	//	tr_.position.x=
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		//右に移動
	//	tr_.position.x=
	}
	if (Input::IsKey(DIK_SPACE))
	{
		//何らかの処理
	//	Instantiate<Bullet>(this);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
