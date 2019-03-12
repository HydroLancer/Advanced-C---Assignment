#pragma once
#include "CSquare.h"
class CPenalty :
	public CSquare
{
public:
	CPenalty(int code, std::string name);
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
	~CPenalty();
};

