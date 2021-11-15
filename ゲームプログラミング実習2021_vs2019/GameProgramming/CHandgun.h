#ifndef CHANDGUN_H
#define CHANDGUN_H

#include "CCharacter.h"

class CHandgun :public CCharacter
{
	CModel mModel;
public:
	//�}�K�W�����̎c�e��
	int mMagazine;
	//�\���̎c�e��
	int mRemainingBullet;
	//�����[�h�t���O
	bool mReload;
	//�����[�h����
	int mReloadTime;

	CHandgun();

	void Update(CMatrix matrix, CVector rotation);
};

#endif