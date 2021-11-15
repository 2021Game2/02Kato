#include "CHandgun.h"
#include "CKey.h"
#include "CBullet.h"

#define MAGAZINE 9 //マガジンに装填できる弾の上限数
#define RELOAD 120 //リロードにかかる時間(2秒)

CHandgun::CHandgun()
:mMagazine(9),mRemainingBullet(45),mReload(false),mReloadTime(RELOAD)
{
	mPosition = CVector(0.0f, 3.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;
}

//プレイヤーの位置と回転が引数のUpdate関数
void CHandgun::Update(CMatrix matrix,CVector rotation)
{
	mMatrix = matrix;
	mRotation = rotation;
	//プレイヤーの手元に移動
	mPosition = CVector(1.0f, 1.0f, -1.0f) * mMatrix;
	//マガジンに弾が入っているならマウスの左クリック入力で弾発射
	if (CKey::Once(VK_LBUTTON)&&mMagazine>0) 
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
	}

	//リロード中
	if (mReload == true)
	{
		//リロードが完了したらリロードフラグをfalseにする
		if (mReloadTime <= 0)
		{
			mReload = false;
			mReloadTime = RELOAD;
		}
		mReloadTime--;
	}

	//リロード中でなければリロードを始める
	if (CKey::Push('R')&&mReload==false)
	{
		int i = 0;
		//マガジンにリロードする弾数
		i= MAGAZINE - mMagazine;
		//予備の弾数からリロードに使う弾数を引く
		mRemainingBullet = mRemainingBullet - i;
		mMagazine += i;
	}

	CTransform::Update();

}