#pragma once
#include "Engine\\GameObject.h"
class Player :
	public GameObject
{
public:
	//初期化
	Player(GameObject* parent);

	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
private:
	int hModel_;
	Transform tr_;//トランスフォーム(アフィン変換用のパラメータを保存してるよ)
};

