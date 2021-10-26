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

	//ディスプレイの左上を原点として起動時のマウスカーソルの座標を覚える
	int mMouseX, mMouseY;
	//ディスプレイの左上を原点としてマウスカーソルの座標を取得するための変数
	int mx, my;
	//ウィンドウの左上を原点としたマウスカーソルの座標を取得するための変数
	int mMouseXw, mMouseYw;

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
