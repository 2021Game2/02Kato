#ifndef CBOMB_H
#define CBOMB_H

#include "CCharacter.h"
#include "CCollider.h"

class CBomb :public CCharacter 
{
	CModel mModel;
public:
	CBomb();

	//爆風用コライダの宣言
	CCollider mColSphereExplosion;
};

#endif
