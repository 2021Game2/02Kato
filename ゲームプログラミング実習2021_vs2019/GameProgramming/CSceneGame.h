#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CXPlayer.h"
#include "CFloor.h"
#include "CRes.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�v���C���[�̃C���X�^���X
	CXPlayer mPlayer;
	//���̃C���X�^���X
	CFloor mFloor;

	~CSceneGame() {

	}
	//�����������̃I�[�o�[���C�h
	void Init() {

		CRes::sModelX.Load(MODEL_FILE);
		//�L�����N�^�[�Ƀ��f����ݒ�
		mPlayer.Init(&CRes::sModelX);

	}
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};

#endif
