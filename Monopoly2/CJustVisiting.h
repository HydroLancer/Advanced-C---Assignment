#pragma once
#include "CSquare.h"
class CJustVisiting :
	public CSquare
{
public:
	CJustVisiting(int code, std::string name);
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
	~CJustVisiting();
};

