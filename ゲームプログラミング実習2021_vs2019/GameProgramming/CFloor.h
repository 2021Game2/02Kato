#ifndef CFLOOR_H
#define CFLOOR_H

#include "CCharacter.h"
#include "CColliderMesh.h"

class CFloor : public CCharacter
{
	CModel mModel;
public:
	CFloor();

	//�R���C�_�̐錾
	CColliderMesh mColliderMesh;

	void Init();

};

#endif
