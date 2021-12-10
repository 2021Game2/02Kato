#include "CBomb.h"

CBomb::CBomb()
:mExplosion(false),mExplosionRange(0)
,mColSphere1(this, &mMatrix, mPosition, 0.5f)
,mColSphereExplosion(this,&mMatrix,mPosition,mExplosionRange)
{
	mPosition = CVector(0.0f, 0.0f, 0.0f);
	mScale = CVector(0.0f, 0.0f, 0.0f);
	CTransform::Update();

	mModel.Load("cube.obj", "cube.mtl");
	mpModel = &mModel;

	CCharacter::mTag = EBOMB;
	mColSphereExplosion.CCollider::mTag = CCollider::EEXPLOSION;
}

void CBomb::Update()
{
	//���������甚���p�R���C�_�̔��a��傫������
	if (mExplosion==true)
	{
		mExplosionRange += 0.01;
		mColSphereExplosion.mRadius = mExplosionRange;
	}
}

//�Փ˔���
//Collision(�R���C�_1,�R���C�_2)
void CBomb::Collision(CCollider* m, CCollider* o)
{
	switch (o->mType)
	{
		//����̃R���C�_�^�C�v���O�p�`�̏ꍇ
	case CCollider::ETRIANGLE:
		//�e�N���X�����N���X�̏ꍇ
		if (o->mpParent->CCharacter::mTag == EFLOOR)
		{
			//�����l
			CVector adjust;
			//�O�p�`�R���C�_�Ƌ��R���C�_�̏Փ˔���
			CCollider::CollisionTriangleSphere(o, m, &adjust);
			//�d�Ȃ�Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition - adjust * -1;
		}
		break;
	case CCollider::ESPHERE:
		//�e�N���X���v���C���[�N���X�̏ꍇ
		if (o->mpParent->CCharacter::mTag == EPLAYER)
		{
			if (m->CCollider::mTag == CCollider::EEXPLOSION)
			{
				
			}
		}
	}
}

//�Փˏ���
void CBomb::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mColSphere1.ChangePriority();
	mColSphereExplosion.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Get()->Collision(&mColSphere1, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mColSphereExplosion, COLLISIONRANGE);
}