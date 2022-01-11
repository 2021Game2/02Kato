#ifndef CCROSSHAIR_H
#define CCROSSHAIR_H

#include "CTask.h"

class CCrossHair:public CTask{
public:

	//色
	float mCrossHairColor;
	//点の大きさ
	float mCrossHairSize;
	//線の長さ
	float mCrossHairLength;
	//線の幅
	float mCrossHairWidth;
	//線の位置
	float mCrossHairRange;

	CCrossHair();

	//クロスヘアを描画
	void Render();
};

#endif
