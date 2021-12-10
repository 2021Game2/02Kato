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
	//爆発したら爆風用コライダの半径を大きくする
	if (mExplosion==true)
	{
		mExplosionRange += 0.01;
		mColSphereExplosion.mRadius = mExplosionRange;
	}
}

//衝突判定
//Collision(コライダ1,コライダ2)
void CBomb::Collision(CCollider* m, CCollider* o)
{
	switch (o->mType)
	{
		//相手のコライダタイプが三角形の場合
	case CCollider::ETRIANGLE:
		//親クラスが床クラスの場合
		if (o->mpParent->CCharacter::mTag == EFLOOR)
		{
			//調整値
			CVector adjust;
			//三角形コライダと球コライダの衝突判定
			CCollider::CollisionTriangleSphere(o, m, &adjust);
			//重ならない位置まで戻す
			mPosition = mPosition - adjust * -1;
		}
		break;
	case CCollider::ESPHERE:
		//親クラスがプレイヤークラスの場合
		if (o->mpParent->CCharacter::mTag == EPLAYER)
		{
			if (m->CCollider::mTag == CCollider::EEXPLOSION)
			{
				
			}
		}
	}
}

//衝突処理
void CBomb::TaskCollision()
{
	//コライダの優先度変更
	mColSphere1.ChangePriority();
	mColSphereExplosion.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mColSphere1, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mColSphereExplosion, COLLISIONRANGE);
}