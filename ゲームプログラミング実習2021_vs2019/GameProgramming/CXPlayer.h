#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter
{
public:
	//�v���C���[�̃q�b�g�|�C���g
	int mHP;
	//�ړ��x�N�g��
	CVector mVec;

	//�N�����̃}�E�X�J�[�\���̍��W���o����
	int mMouseX;
	int mMouseY;
	//�}�E�X�J�[�\���̍��W���擾���邽�߂̕ϐ�
	int mx, my;

	CXPlayer();

	/*
	������(X���f���N���X�̃|�C���^)
	*/
	void Init(CModelX* model);

	void Update();

private:
	//�W�����v�t���O
	bool mJump;

};

#endif
