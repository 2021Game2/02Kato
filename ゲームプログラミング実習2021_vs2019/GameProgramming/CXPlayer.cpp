#include "CXPlayer.h"
#include "CKey.h"
#include <math.h>
#include "CInput.h"

#define GRAVITY -0.03 //�d��

CXPlayer::CXPlayer()
	:mHP(100), mJump(true)
{
	//�N�����̃}�E�X�J�[�\���̍��W���o����
	CInput::GetMousePos(&mMouseX, &mMouseY);

	//�^�O�Ƀv���C���[��ݒ肵�܂�
	mTag = EPLAYER;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
}

void CXPlayer::Update()
{
	CInput::GetMousePos(&mx, &my);
	if (mx < mMouseX) 
	{
		//�}�E�X�̈ړ��ʂ̕�������]
		mRotation.mY += (mMouseX - mx) / 6.0;
	}
	if (mMouseX < mx) 
	{
		//�}�E�X�̈ړ��ʂ̕�������]
		mRotation.mY += (mMouseX - mx) / 6.0;
	}
	/*if (my < mMouseY)
	{
		//�}�E�X�̈ړ��ʂ̕�������]
		mRotation.mX += (mMouseY - my) / 6.0;
	}
	if (mMouseY < my)
	{
		//�}�E�X�̈ړ��ʂ̕�������]
		mRotation.mX += (mMouseY - my) / 6.0;
	}*/

	//�O�Ɉړ�
	if (CKey::Push('W'))
	{
		mPosition += CVector(0.0f, 0.0f, -0.1f) * mMatrixRotate;

		//����
		if (CKey::Push(VK_SHIFT)) 
		{
			mPosition += CVector(0.0f, 0.0f, -0.03f) * mMatrixRotate;
		}
	}

	//���Ɉړ�
	if (CKey::Push('A'))
	{
		mPosition += CVector(-0.1f, 0.0f, 0.0f) * mMatrixRotate;
	}

	//���Ɉړ�
	if (CKey::Push('S'))
	{
		mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
	}

	//�E�Ɉړ�
	if (CKey::Push('D'))
	{
		mPosition += CVector(0.1f, 0.0f, 0.0f) * mMatrixRotate;
	}

	//�W�����v
	if (CKey::Once(' ') && mJump == true) 
	{
		mVec.mY = 0.5;
		mJump = false;
	}
	//���n�����玟�̃W�����v�\
	if (mPosition.mY <= 0)
	{
		if (mJump == true) {
			mVec.mY = 0;
		}
		mJump = true;
	}

	//�d�͂ɂ��~��
	mPosition += mVec;

	//�d��
	mVec.mY += GRAVITY;

	//�}�E�X�J�[�\����\��
	if (CKey::Once(VK_ESCAPE))
	{
		ShowCursor(true);
	}

	CXCharacter::Update();

	//�ȑO�̃J�[�\�����W��V�������W�ɍX�V
	mMouseX = mx;
	mMouseY = my;

}
