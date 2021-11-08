#include "CBomb.h"

CBomb::CBomb()
{
	mPosition = CVector(0.0f, 0.0f, 0.0f);
	mScale = CVector(0.0f, 0.0f, 0.0f);
	CTransform::Update();

	mModel.Load("sky.obj", "sky.mtl");
	mpModel = &mModel;
}