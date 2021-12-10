#ifndef CASSAULTRIFLE_H
#define CASSAULTLIFLE_H

#include "CGun.h"

class CAssaultRifle :public CGun
{
	CModel mModel;
public:

	CAssaultRifle();

	void Update(CMatrix matrix, CVector rotation);

};

#endif
