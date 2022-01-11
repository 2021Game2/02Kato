#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CXPlayer.h"
#include "CFloor.h"
#include "CRes.h"

/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	//プレイヤーのインスタンス
	CXPlayer mPlayer;
	//床のインスタンス
	CFloor mFloor;

	~CSceneGame() {

	}
	//初期化処理のオーバーライド
	void Init() {

		CRes::sModelX.Load(MODEL_FILE);
		//キャラクターにモデルを設定
		mPlayer.Init(&CRes::sModelX);

	}
	//更新処理のオーバーライド
	void Update();

};

#endif
