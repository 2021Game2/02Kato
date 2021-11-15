#ifndef CXPLAYER_H
#define CXPLAYER_H

#include "CXCharacter.h"
#include "CCollider.h"
#include "CHandgun.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"

class CXPlayer : public CXCharacter
{
public:
	//�v���C���[�̃q�b�g�|�C���g
	int mHP;
	//�ړ��x�N�g��
	CVector mVec;

	//�f�B�X�v���C�̍�������_�Ƃ��ċN�����̃}�E�X�J�[�\���̍��W���o����
	int mMouseX, mMouseY;
	//�f�B�X�v���C�̍�������_�Ƃ��ă}�E�X�J�[�\���̍��W���擾���邽�߂̕ϐ�
	int mx, my;
	//�E�B���h�E�̍�������_�Ƃ����}�E�X�J�[�\���̍��W���擾���邽�߂̕ϐ�
	int mMouseXw, mMouseYw;
	//�}�E�X���x
	int mMouseSensitivity;

	//�n���h�K���̃C���X�^���X
	CHandgun mHandgun;

	//�R���C�_�̐錾
	CCollider mColSphere1;
	CCollider mColSphere2;
	CCollider mColSphere3;

	CXPlayer();

	/*
	������(X���f���N���X�̃|�C���^)
	*/
	void Init(CModelX* model);

	void Update();

	//�Փ˔���
	void Collision(CCollider* m, CCollider* o);
	//�Փˏ���
	void TaskCollision();

private:
	//�W�����v�t���O�@�W�����v�\:true �W�����v�s��:false
	bool mJump;
	//���n�t���O ���n:true ��:false
	bool mLanding;

};

#endif
