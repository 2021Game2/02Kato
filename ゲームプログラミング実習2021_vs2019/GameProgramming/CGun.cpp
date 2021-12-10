#include "CGun.h"

CGun::CGun()
:mMagazine(0),mMagazineMax(0), mRemainingBullet(0), mReload(false)
, mReloadTime(0),mReloadTimeMax(0){}

void CGun::Reroad()
{
	//リロード中
	if (mReload == true)
	{
		//リロードが完了したらリロードフラグをfalseにする
		if (mReloadTime <= 0)
		{
			mReload = false;
			mReloadTime = mReloadTimeMax;
		}
		mReloadTime--;
	}

	//リロード中でなければリロードを始める
	if (CKey::Push('R') && mReload == false)
	{
		int i = 0;
		//マガジンにリロードする弾数
		i = mMagazineMax - mMagazine;
		//予備の弾数からリロードに使う弾数を引く
		mRemainingBullet = mRemainingBullet - i;
		mMagazine += i;
	}
}