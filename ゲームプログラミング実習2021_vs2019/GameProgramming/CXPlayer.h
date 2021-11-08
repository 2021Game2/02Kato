#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"
#include "CHandgun.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"

class CXPlayer : public CXCharacter
{
public:
	//プレイヤーのヒットポイント
	int mHP;
	//移動ベクトル
	CVector mVec;

	//ディスプレイの左上を原点として起動時のマウスカーソルの座標を覚える
	int mMouseX, mMouseY;
	//ディスプレイの左上を原点としてマウスカーソルの座標を取得するための変数
	int mx, my;
	//ウィンドウの左上を原点としたマウスカーソルの座標を取得するための変数
	int mMouseXw, mMouseYw;

	//ハンドガンのインスタンス
	CHandgun mHandgun;

	//コライダの宣言
	CCollider mColSphere1;
	CCollider mColSphere2;
	CCollider mColSphere3;

	CXPlayer();

	/*
	初期化(Xモデルクラスのポインタ)
	*/
	void Init(CModelX* model);

	void Update();

	//衝突判定
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void TaskCollision();

private:
	//ジャンプフラグ
	bool mJump;

};

#endif
