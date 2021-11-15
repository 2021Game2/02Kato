#include "CFloor.h"

CFloor::CFloor()
{
	mPosition = CVector(0.0f, -1.0f, 0.0f);
	mScale = CVector(50.0f, 0.1f, 50.0f);
	CTransform::Update();

	mModel.Load("cube.obj", "cube.mtl");
	mpModel = &mModel;

	CCharacter::mTag = EFLOOR;
	Init();
}

void CFloor::Init()
{
	//���f������O�p�R���C�_�𐶐�
	mColliderMesh.Set(this, &mMatrix, mpModel);
}
