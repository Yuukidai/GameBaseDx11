#include "Player.h"
#include "Bullet.h"
#include "Engine/Model.h" //\\でもオッケー
#include "Engine/Input.h"


Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}
//playerの初期位置0f -4.0f 0f
void Player::Initialize()
{
	hModel_ = Model::Load("furai.fbx");
	assert(hModel_ >= 0);//読み込みに失敗したらすぐエラーになって落ちるのはゲーム的にはよくないけど開発中はおｋ
	tr_.position_ = { 0.0f, -4.0f,0.0f };
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		tr_.position_.x = tr_.position_.x - 0.1;
	}

	if (Input::IsKey(DIK_RIGHT)|| Input::IsKey(DIK_D))
	{
		tr_.position_.x = tr_.position_.x + 0.1;
	}

	if (Input::IsKey(DIK_SPACE))
	{
		Bullet * pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
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
