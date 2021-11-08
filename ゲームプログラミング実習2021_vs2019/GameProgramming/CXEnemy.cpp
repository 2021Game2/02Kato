#include "CXEnemy.h"

CXEnemy::CXEnemy()
:mHP(100)
{

}

void CXEnemy::Init(CModelX* model)
{
	CXCharacter::Init(model);
}

void CXEnemy::Update()
{

	//HPÇ™0à»â∫Ç…Ç»ÇÈÇ∆è¡Ç¶ÇÈ
	if (mHP <=0)
	{
		delete this;
	}
}

void CXEnemy::Collision(CCollider* m, CCollider* o)
{

}
