#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CXPlayer.h"
#include "CFloor.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�v���C���[�̃C���X�^���X
	CXPlayer mPlayer;
	//���̃C���X�^���X
	CFloor mFloor;

	~CSceneGame();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};

#endif
