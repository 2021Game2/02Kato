#include "CAssaultRifle.h"
#include "CBullet.h"

CAssaultRifle::CAssaultRifle()
{
	mPosition = CVector(0.0f, 3.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;

	//�}�K�W���ɓ���e�̍ő�l��ݒ�
	mMagazineMax = 30;
	//�}�K�W���̎c�e�����ő�ɐݒ�
	mMagazine = mMagazineMax;
	//�����[�h�ɂ����鎞�Ԃ�ݒ�
	mReloadTimeMax = 180;
	mReloadTime = mReloadTimeMax;
}

void CAssaultRifle::Update(CMatrix matrix, CVector rotation)
{
	mMatrix = matrix;
	mRotation = rotation;
	//�v���C���[�̎茳�Ɉړ�
	mPosition = CVector(1.0f, 1.0f, -1.0f) * mMatrix;

	//�}�K�W���ɒe�������Ă���Ȃ�}�E�X�̍��N���b�N���͂Œe����
	if (CKey::Once(VK_LBUTTON) && mMagazine > 0)
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
	}

	//�e�N���X�̃����[�h�֐����Ă�
	Reroad();
}
