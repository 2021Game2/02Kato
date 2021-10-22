#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CXPlayer.h"
#include "CFloor.h"

/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	//プレイヤーのインスタンス
	CXPlayer mPlayer;
	//床のインスタンス
	CFloor mFloor;

	~CSceneGame();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

};

#endif
