#pragma once
#include "CSquare.h"
class CFreeParking :
	public CSquare
{
public:
	CFreeParking(int code, std::string name);
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);
	~CFreeParking();
};

