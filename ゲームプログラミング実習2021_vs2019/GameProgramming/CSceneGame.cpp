#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CUtil.h"
//
#include "CRes.h"

#include "Ckey.h"
//
#include "CMaterial.h"
//
#include "CCollisionManager.h"
//
#include "CInput.h"

CMatrix Matrix;

void CSceneGame::Update() {
	//�}�E�X�J�[�\�����\��
	ShowCursor(false);
	CTaskManager::Get()->Update();
	
	//�Փˏ���
	//CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = mPlayer.mPosition;
	//�����_�����߂�
	c = mPlayer.mPosition + CVector(0.0f, 0.0f, 1.0f) * mPlayer.mMatrixRotate;
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	/*e = mPlayer.mHandgun.mPosition + CVector(0.0f, 0.0f, 1.0f);
	c = mPlayer.mHandgun.mPosition;
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mHandgun.mMatrixRotate;
	*/

	/*e = CVector(0.0f, 4.0f, 5.0f);
	c = mPlayer.mPosition;
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;
	*/
	

	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

	//X���{��]
	if (CKey::Push('K')) {
		Matrix = Matrix * CMatrix().RotateX(1);
	}
	if (CKey::Push('I')) {
		Matrix = Matrix * CMatrix().RotateX(-1);
	}
	//Y���{��]
	if (CKey::Push('L')) {
		Matrix = Matrix * CMatrix().RotateY(1);
	}
	if (CKey::Push('J')) {
		Matrix = Matrix * CMatrix().RotateY(-1);
	}

	//�s��ݒ�
	glMultMatrixf(Matrix.mF);

	//�`��
	CTaskManager::Get()->Render();

	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();

	return;
}

