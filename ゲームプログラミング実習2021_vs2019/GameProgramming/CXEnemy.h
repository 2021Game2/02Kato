#ifndef CXENEMY_H
#define CXENEMY_H

#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy : public CXCharacter
{
public:
	//�G�l�~�[�̃q�b�g�|�C���g
	int mHP;

	CXEnemy();
	/*
	������(X���f���N���X�̃|�C���^)
	*/
	void Init(CModelX* model);
	
	void Update();

	//�Փˏ���
	//m:�����̃R���C�_ o:����̃R���C�_
	void Collision(CCollider* m, CCollider* o);

};

#endif
