#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = { 0.0f,0.0f,0.0f };
    transform_.scale_ = { 0.5f,0.5f,0.5f };
    transform_.rotate_ = { 0.0f,0.0f,0.0f };

    SphereCollider* collider =  new SphereCollider(XMFLOAT3(0.0f,0.0f,0.0f ),1.0f);
    AddCollider(collider);

}

void Enemy::Update()
{
    static float time = 0.0f;

    time += 0.025;
    //float posx = 6.0 * sin(0.2f * time);
    //float posy = cos(3.0f * time);
    //ot_.position_.x = posx;
    //ot_.position_.y = posy;


}

void Enemy::Draw()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    
}

void Enemy::Release()
{
    Model::SetTransform(hModel_, tr_);
    Model::Draw(hModel_);
}
