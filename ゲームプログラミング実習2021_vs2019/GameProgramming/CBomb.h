#ifndef CBOMB_H
#define CBOMB_H

#include "CCharacter.h"
#include "CCollider.h"

class CBomb :public CCharacter 
{
	CModel mModel;
public:
	CBomb();

	//�����p�R���C�_�̐錾
	CCollider mColSphereExplosion;
};

#endif
