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

	//HP��0�ȉ��ɂȂ�Ə�����
	if (mHP <=0)
	{
		delete this;
	}
}

void CXEnemy::Collision(CCollider* m, CCollider* o)
{

}
