#include "CHandgun.h"
#include "CKey.h"
#include "CBullet.h"

CHandgun::CHandgun()
{
	mPosition = CVector(0.0f, 3.0f, 0.0f);
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();

	mModel.Load("Handgun.obj", "Handgun.mtl");
	mpModel = &mModel;
}

//�v���C���[�̈ʒu�Ɖ�]��������Update�֐�
void CHandgun::Update(CMatrix matrix,CVector rotation)
{
	mMatrix = matrix;
	mRotation = rotation;
	//�v���C���[�̎茳�Ɉړ�
	mPosition = CVector(1.0f, 1.0f, -1.0f) * mMatrix;
	//�}�E�X�̍��N���b�N���͂Œe����
	if (CKey::Once(VK_LBUTTON)) {
		CBullet* bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
	}

	CTransform::Update();

}