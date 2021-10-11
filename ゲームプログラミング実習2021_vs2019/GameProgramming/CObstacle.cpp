#include "CObstacle.h"

CObstacle::CObstacle()
:mColSphere(this, nullptr, CVector(0.0f, 0.0f, 0.0f), 1.0f)
{
	mPosition = CVector(0.0f, 0.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f,1.0f);
	CTransform::Update();

	mModel.Load("cube.obj", "cube.mtl");
	mpModel = &mModel;
}
