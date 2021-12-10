#ifndef CGUN_H
#define CGUN_H

#include "CCharacter.h"
#include "CKey.h"

//武器の親クラス
class CGun :public CCharacter
{
public:
	//マガジン内の残弾数
	int mMagazine;
	//マガジン内に入れれる弾の最大値
	int mMagazineMax;
	//予備の残弾数
	int mRemainingBullet;
	//リロードフラグ リロード中
	bool mReload;
	//残りのリロード時間
	int mReloadTime;
	//リローダ開始から終了までに必要な時間
	int mReloadTimeMax;

	CGun();

	//リロードする
	void Reroad();

	virtual void Update(CMatrix matrix, CVector rotation) {};
};

#endif
