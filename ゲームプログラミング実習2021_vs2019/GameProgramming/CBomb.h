#ifndef CBOMB_H
#define CBOMB_H

#include "CCharacter.h"
#include "CCollider.h"
#include "CCollisionManager.h"

class CBomb :public CCharacter 
{
	CModel mModel;
public:
	//�����͈�
	float mExplosionRange;
	//���j����
	bool mExplosion;

	CBomb();

	//���e�{�̂̃R���C�_
	CCollider mColSphere1;
	//�����p�R���C�_�̐錾
	CCollider mColSphereExplosion;
	
	void Update();

	//�Փ˔���
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	void TaskCollision();

};

#endif
