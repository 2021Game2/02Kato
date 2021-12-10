#include "CAssaultRifle.h"
#include "CBullet.h"

CAssaultRifle::CAssaultRifle()
{
	mPosition = CVector(0.0f, 3.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;

	//マガジンに入る弾の最大値を設定
	mMagazineMax = 30;
	//マガジンの残弾数を最大に設定
	mMagazine = mMagazineMax;
	//リロードにかかる時間を設定
	mReloadTimeMax = 180;
	mReloadTime = mReloadTimeMax;
}

void CAssaultRifle::Update(CMatrix matrix, CVector rotation)
{
	mMatrix = matrix;
	mRotation = rotation;
	//プレイヤーの手元に移動
	mPosition = CVector(1.0f, 1.0f, -1.0f) * mMatrix;

	//マガジンに弾が入っているならマウスの左クリック入力で弾発射
	if (CKey::Once(VK_LBUTTON) && mMagazine > 0)
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
	}

	//親クラスのリロード関数を呼ぶ
	Reroad();
}
