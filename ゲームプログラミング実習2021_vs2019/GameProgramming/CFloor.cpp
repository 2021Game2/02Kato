#include "CFloor.h"

CFloor::CFloor()
{
	mPosition = CVector(0.0f, -1.2f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Street environment_V02.obj", "Street environment_V02.mtl");
	mpModel = &mModel;

	CCharacter::mTag = EFLOOR;
}

void CFloor::Init()
{
	//���f������O�p�R���C�_�𐶐�
	mColliderMesh.Set(this, &mMatrix, mpModel);
}
