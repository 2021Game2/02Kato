#ifndef CHANDGUN_H
#define CHANDGUN_H

#include "CCharacter.h"

class CHandgun :public CCharacter
{
	CModel mModel;
public:
	//マガジン内の残弾数
	int mMagazine;
	//予備の残弾数
	int mRemainingBullet;
	//リロードフラグ リロード中
	bool mReload;
	//リロード時間
	int mReloadTime;

	CHandgun();

	void Update(CMatrix matrix, CVector rotation);
};

#endif