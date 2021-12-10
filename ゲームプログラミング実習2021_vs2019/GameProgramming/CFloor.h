#ifndef CFLOOR_H
#define CFLOOR_H

#include "CCharacter.h"
#include "CColliderMesh.h"

class CFloor : public CCharacter
{
	CModel mModel;
public:
	CFloor();

	//ƒRƒ‰ƒCƒ_‚ÌéŒ¾
	CColliderMesh mColliderMesh;

	void Init();

};

#endif
