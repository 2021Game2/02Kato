#include "CXPlayer.h"
#include "CKey.h"
#include <math.h>
#include "CInput.h"

#define GRAVITY -0.03 //�d��
#define WINDOW_WIDTH 800 //�E�B���h�E�̉��̒���
#define WINDOW_HEIGHT 600 //�E�B���h�E�̏c�̒���

CXPlayer::CXPlayer()
	:mHP(100), mJump(true)
	, mColSphere1(this, &mMatrix, mPosition+CVector(0.0f, 1.0f, 0.0f), 0.5f)
	, mColSphere2(this, &mMatrix, mPosition, 0.5f)
	, mColSphere3(this, &mMatrix, mPosition+CVector(0.0f, -1.0f, 0.0f), 0.5f)
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
	//�J�����̌������^��łȂ����
	if (mRotation.mX<90)
	{
		if (my < mMouseY)
		{
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mX += (mMouseY - my) / 6.0;
		}
	}
	//�J�����̌������^���łȂ����
	if (mRotation.mX>-90)
	{
		if (mMouseY < my)
		{
			//�}�E�X�̈ړ��ʂ̕�������]
			mRotation.mX += (mMouseY - my) / 6.0;
		}
	}

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

	//HP��0�ȉ��ɂȂ�ƃv���C���[�͏�����
	if (mHP <= 0) {
		delete this;
	}

	//�}�E�X�J�[�\����\��
	if (CKey::Once(VK_ESCAPE))
	{
		ShowCursor(true);
	}

	//�ȑO�̃J�[�\�����W��V�������W�ɍX�V
	mMouseX = mx;
	mMouseY = my;

	//�J�[�\�����E�B���h�E�̊O�ɏo����E�B���h�E���ɃJ�[�\����߂�
	CInput::GetMousePosW(&mMouseXw, &mMouseYw);
	//�E�B���h�E�̉E�[���J�[�\�����E�ɏo����E�B���h�E���ɃJ�[�\����߂�
	if (mMouseXw > WINDOW_WIDTH)
	{
		mMouseX -= WINDOW_WIDTH;
		CInput::SetMousePos(mx - WINDOW_WIDTH, my);
	}
	//�E�B���h�E�̍��[���J�[�\�������ɏo����E�B���h�E���ɃJ�[�\����߂�
	if (mMouseXw < 0)
	{
		mMouseX += WINDOW_WIDTH;
		CInput::SetMousePos(mx + WINDOW_WIDTH, my);
	}
	//�E�B���h�E�̏�[���J�[�\������ɏo����E�B���h�E���ɃJ�[�\����߂�
	if (mMouseYw < 0)
	{
		mMouseY += WINDOW_HEIGHT;
		CInput::SetMousePos(mx, my + WINDOW_HEIGHT);
	}
	//�E�B���h�E�̉��[���J�[�\�������ɏo����E�B���h�E���ɃJ�[�\����߂�
	if (mMouseYw > WINDOW_HEIGHT)
	{
		mMouseY -= WINDOW_HEIGHT;
		CInput::SetMousePos(mx, my - WINDOW_HEIGHT);
	}

	//Handgun�N���X�̃A�b�v�f�[�g
	mHandgun.Update(mMatrix, mRotation);
	mHandgun.Render();

	CTransform::Update();

	CXCharacter::Update();
}

//�Փ˔���
//Collision(�R���C�_1,�R���C�_2)
void CXPlayer::Collision(CCollider* m, CCollider* o)
{
	switch (o->mType)
	{
	//����̃R���C�_�^�C�v���O�p�`�̏ꍇ
	case CCollider::ETRIANGLE:
		//�e�N���X�����N���X�̏ꍇ
		if(o->mpParent->CCharacter::mTag == EFLOOR)
		{
			//�����l
			CVector adjust;
			//�O�p�`�R���C�_�Ƌ��R���C�_�̏Փ˔���
			CCollider::CollisionTriangleSphere(o, m, &adjust);
			//�d�Ȃ�Ȃ��ʒu�܂Ŗ߂�
			mPosition = mPosition + adjust;
		}
		break;
	}
}

//�Փˏ���
void CXPlayer::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mColSphere1.ChangePriority();
	mColSphere2.ChangePriority();
	mColSphere3.ChangePriority();
	//�Փˏ��������s
	CCollisionManager::Get()->Collision(&mColSphere1, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mColSphere2, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mColSphere3, COLLISIONRANGE);
}