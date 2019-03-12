#pragma once
#include "CSquare.h"
class CBonus :
	public CSquare
{
public:
	CBonus(int code, std::string name);
	void LandedOn(CPlayer* player1, CPlayer* player2);
	~CBonus();
};

