#ifndef CCROSSHAIR_H
#define CCROSSHAIR_H

#include "CTask.h"

class CCrossHair:public CTask{
public:

	//�F
	float mCrossHairColor;
	//�_�̑傫��
	float mCrossHairSize;
	//���̒���
	float mCrossHairLength;
	//���̕�
	float mCrossHairWidth;
	//���̈ʒu
	float mCrossHairRange;

	CCrossHair();

	//�N���X�w�A��`��
	void Render();
};

#endif
