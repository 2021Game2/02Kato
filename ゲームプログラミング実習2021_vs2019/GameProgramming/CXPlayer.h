#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//プレイヤーのヒットポイント
	int mHP;
	//移動ベクトル
	CVector mVec;

	//起動時のマウスカーソルの座標を覚える
	int mMouseX;
	int mMouseY;
	//マウスカーソルの座標を取得するための変数
	int mx, my;

	CXPlayer();

	/*
	初期化(Xモデルクラスのポインタ)
	*/
	void Init(CModelX* model);

	void Update();

private:
	//ジャンプフラグ
	bool mJump;

};

#endif
