#include "CHandgun.h"
#include "CKey.h"
#include "CBullet.h"

#define MAGAZINE 9 //�}�K�W���ɑ��U�ł���e�̏����
#define RELOAD 120 //�����[�h�ɂ����鎞��(2�b)

CHandgun::CHandgun()
:mMagazine(MAGAZINE),mRemainingBullet(45),mReload(false)
,mReloadTime(RELOAD)
{
	mPosition = mPosition+CVector(2.0f, -1.0f, -1.5f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mRotation = CVector(0.0f, 0.0f, 0.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;
}

//�v���C���[�̈ʒu�Ɖ�]��������Update�֐�
void CHandgun::Update(CMatrix matrix,CVector rotation)
{
	//
	mRotation = CVector(-2.0f, 80.0f, 0.0f) + rotation;
	//�v���C���[�̎茳�Ɉړ�
	mPosition = CVector(1.0f, -1.0f, -2.0f) * matrix;
	//�}�K�W���ɒe�������Ă���Ȃ�}�E�X�̍��N���b�N���͂Œe����
	if (CKey::Push(VK_LBUTTON) && mMagazine>0)
	{
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 1.0f, 0.0f) * mMatrix;
		bullet->mRotation = rotation;
	}
	
	//�ʒu�����p�̎��_����
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