#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();

	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放

	void OnCollision(GameObject* pTarget)override;
	void Release() override;
private:
	int hModel_;
	Transform tr_;
};

