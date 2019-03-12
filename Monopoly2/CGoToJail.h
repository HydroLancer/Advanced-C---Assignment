#pragma once
#include "CSquare.h"
class CGoToJail :
	public CSquare
{
public:
	CGoToJail(int code, std::string name);
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
	~CGoToJail();
};

