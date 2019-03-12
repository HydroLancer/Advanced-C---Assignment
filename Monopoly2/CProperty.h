#pragma once
#include "CSquare.h"
#include "CPlayer.h"
#include "MonopolyHeader.hpp"
class CProperty :
	public CSquare
{
protected:
	int mCost;
	int mRent;
	int mGroup;
public:
	CProperty(int code, std::string name, int cost, int rent, int group);
	void LandedOn(CPlayer* player1, CPlayer* player2);
	void Buy(CPlayer* player);
	int CheckForOwnership();
	~CProperty();
};

