#ifndef CHANDGUN_H
#define CHANDGUN_H

#include "CCharacter.h"

class CHandgun :public CCharacter
{
	CModel mModel;
public:
	CHandgun();

	void Update(CMatrix matrix, CVector rotation);
};

#endif