#include "CGun.h"

CGun::CGun()
:mMagazine(0),mMagazineMax(0), mRemainingBullet(0), mReload(false)
, mReloadTime(0),mReloadTimeMax(0){}

void CGun::Reroad()
{
	//�����[�h��
	if (mReload == true)
	{
		//�����[�h�����������烊���[�h�t���O��false�ɂ���
		if (mReloadTime <= 0)
		{
			mReload = false;
			mReloadTime = mReloadTimeMax;
		}
		mReloadTime--;
	}

	//�����[�h���łȂ���΃����[�h���n�߂�
	if (CKey::Push('R') && mReload == false)
	{
		int i = 0;
		//�}�K�W���Ƀ����[�h����e��
		i = mMagazineMax - mMagazine;
		//�\���̒e�����烊���[�h�Ɏg���e��������
		mRemainingBullet = mRemainingBullet - i;
		mMagazine += i;
	}
}