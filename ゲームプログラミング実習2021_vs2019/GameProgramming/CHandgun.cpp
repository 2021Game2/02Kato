#include "CHandgun.h"
#include "CKey.h"
#include "CBullet.h"

#define MAGAZINE 9 //�}�K�W���ɑ��U�ł���e�̏����
#define RELOAD 120 //�����[�h�ɂ����鎞��(2�b)

CHandgun::CHandgun()
:mMagazine(9),mRemainingBullet(45),mReload(false),mReloadTime(RELOAD)
{
	mPosition = CVector(0.0f, 3.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;
}

//�v���C���[�̈ʒu�Ɖ�]��������Update�֐�
void CHandgun::Update(CMatrix matrix,CVector rotation)
{
	mMatrix = matrix;
	mRotation = rotation;
	//�v���C���[�̎茳�Ɉړ�
	mPosition = CVector(1.0f, 1.0f, -1.0f) * mMatrix;
	//�}�K�W���ɒe�������Ă���Ȃ�}�E�X�̍��N���b�N���͂Œe����
	if (CKey::Once(VK_LBUTTON)&&mMagazine>0) 
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
	}

	//�����[�h��
	if (mReload == true)
	{
		//�����[�h�����������烊���[�h�t���O��false�ɂ���
		if (mReloadTime <= 0)
		{
			mReload = false;
			mReloadTime = RELOAD;
		}
		mReloadTime--;
	}

	//�����[�h���łȂ���΃����[�h���n�߂�
	if (CKey::Push('R')&&mReload==false)
	{
		int i = 0;
		//�}�K�W���Ƀ����[�h����e��
		i= MAGAZINE - mMagazine;
		//�\���̒e�����烊���[�h�Ɏg���e��������
		mRemainingBullet = mRemainingBullet - i;
		mMagazine += i;
	}

	CTransform::Update();

}