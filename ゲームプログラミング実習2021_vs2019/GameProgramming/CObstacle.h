#ifndef COBSTACLE_H
#define COBSTACLE_H

#include "CCharacter.h"
#include "CCollider.h"

class CObstacle :public CCharacter 
{
	CModel mModel;
public:
	CCollider mColSphere;
	//コンストラクタ
	CObstacle();
};

#endif
