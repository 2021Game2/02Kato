#include "CFloor.h"

CFloor::CFloor()
{
	mPosition = CVector(0.0f, 0.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Street environment_V01.obj", "Street environment_V01.mtl");
	mpModel = &mModel;
}
