#ifndef CGUN_H
#define CGUN_H

#include "CCharacter.h"
#include "CKey.h"

//����̐e�N���X
class CGun :public CCharacter
{
public:
	//�}�K�W�����̎c�e��
	int mMagazine;
	//�}�K�W�����ɓ�����e�̍ő�l
	int mMagazineMax;
	//�\���̎c�e��
	int mRemainingBullet;
	//�����[�h�t���O �����[�h��
	bool mReload;
	//�c��̃����[�h����
	int mReloadTime;
	//�����[�_�J�n����I���܂łɕK�v�Ȏ���
	int mReloadTimeMax;

	CGun();

	//�����[�h����
	void Reroad();

	virtual void Update(CMatrix matrix, CVector rotation) {};
};

#endif
