#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CFloor.h"

/*
ゲームのシーン
*/
class CSceneGame : public CScene {
private:
	//床のインスタンス
	CFloor mFloor;
public:
	~CSceneGame();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

};

#endif
