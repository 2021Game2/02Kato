#ifndef CBOMB_H
#define CBOMB_H

#include "CCharacter.h"
#include "CCollider.h"
#include "CCollisionManager.h"

class CBomb :public CCharacter 
{
	CModel mModel;
public:
	//爆発範囲
	float mExplosionRange;
	//爆破判定
	bool mExplosion;

	CBomb();

	//爆弾本体のコライダ
	CCollider mColSphere1;
	//爆風用コライダの宣言
	CCollider mColSphereExplosion;
	
	void Update();

	//衝突判定
	void Collision(CCollider* m, CCollider* o);
	//衝突処理
	void TaskCollision();

};

#endif
