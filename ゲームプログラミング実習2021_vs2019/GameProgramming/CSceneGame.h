#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CFloor.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
private:
	//���̃C���X�^���X
	CFloor mFloor;
public:
	~CSceneGame();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};

#endif
