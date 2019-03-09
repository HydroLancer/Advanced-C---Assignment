#pragma once
#include "CSquare.h"
#include "CPlayer.h"
#include "MonopolyHeader.hpp"

class CSpecial :
	public CSquare
{
protected:
public:
	CSpecial(int code, std::string name);
	std::string ReturnName();
	void LandedOn(CPlayer* player1, CPlayer* player2);
	void Buy(CPlayer* player);
	int CheckForOwnership();
	~CSpecial();
};

