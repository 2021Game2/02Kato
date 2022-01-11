#include "CHandgun.h"
#include "CKey.h"
#include "CBullet.h"

#define MAGAZINE 9 //マガジンに装填できる弾の上限数
#define RELOAD 120 //リロードにかかる時間(2秒)

CHandgun::CHandgun()
:mMagazine(MAGAZINE),mRemainingBullet(45),mReload(false)
,mReloadTime(RELOAD)
{
	mPosition = mPosition+CVector(-1.0f, -1.0f, 1.5f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mRotation = CVector(-2.0f, 4.0f, 0.0f);
	CTransform::Update();
	//行列を退避
	mLocalMatrix = mMatrix;

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;
}

//プレイヤーの位置と回転が引数のUpdate関数
void CHandgun::Update(CMatrix matrix,CVector rotation)
{
	//武器を画面外から画面内の指定の位置に来るまで上昇
    

	//マガジンに弾が入っているならマウスの左クリック入力で弾発射
	if (CKey::Once(VK_LBUTTON) && mMagazine>0)
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.5f, 2.0f) * mMatrix;
		bullet->mRotation = rotation;
	}
	
	//位置調整用の視点操作
	if (CKey::Push('Z'))
	{
		mRotation += CVector(1.0f, 0.0f, 0.0f);
	}
	if (CKey::Push('X'))
	{
		mRotation += CVector(-1.0f, 0.0f, 0.0f);
	}
	if (CKey::Push('C'))
	{
		mRotation += CVector(0.0f, 1.0f, 0.0f);
	}
	if (CKey::Push('V'))
	{
		mRotation += CVector(0.0f, -1.0f, 0.0f);
	}
	if (CKey::Push('B'))
	{
		mRotation += CVector(0.0f, 0.0f, 1.0f);
	}
	if (CKey::Push('N'))
	{
		mRotation += CVector(0.0f, 0.0f, -1.0f);
	}

	//リロード中
	if (mReload == true)
	{
		mReloadTime--;
		//リロードが完了したらリロードフラグをfalseにする
		if (mReloadTime <= 0)
		{
			mReload = false;
			mReloadTime = RELOAD;
		}
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

	mMatrix = mLocalMatrix * matrix;
}