#ifndef COBSTACLE_H
#define COBSTACLE_H

#include "CCharacter.h"
#include "CCollider.h"

class CObstacle :public CCharacter 
{
	CModel mModel;
public:
	CCollider mColSphere;
	//�R���X�g���N�^
	CObstacle();
};

#endif
