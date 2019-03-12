#pragma once
#include "CSquare.h"
class CGo :
	public CSquare
{
public:
	CGo(int code, std::string name);
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
	~CGo();
};

