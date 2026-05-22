#include "PlayScene.h"
#include "Engine/Model.h" //\\でもオッケー
#include "Player.h"
#include "Bullet.h"
#include "Engine/SceneManager.h"


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
	Instantiate<Player>(this);//playerのインスタンス＝プレイヤーのオブジェクトを作る
	Instantiate<Bullet>(this);
	//Instantiate<Bullet>(this);



}

void PlayScene::Update()
{
	if (FindObject("Enemy")== nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);//スペースキー押したらプレイシーンを探して切り替える
	}
	
}

void PlayScene::Draw()
{	
	Model::SetTransform(hModel_ , ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
