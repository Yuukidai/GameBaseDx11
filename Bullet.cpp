#include "Bullet.h"
#include "Engine/Model.h"
#include "player.h"
#include "Player.h"
#include "Engine/SphereCollider.h"


Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),hModel_(-1),speed_(0.5f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("bullet.fbx");
	assert(hModel_ >= 0);
	//Player* player = (Player*)GetParent();

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);

}
void Bullet::Update()
{

	tr_.position_.z = tr_.position_.z + speed_;
	if (transform_.position_.z > 50.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
