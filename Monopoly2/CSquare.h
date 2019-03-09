#pragma once
#include "MonopolyHeader.hpp"
#include "CPlayer.h"

class CSquare
{
protected:
	int mCode;
	std::string mName;
	bool isOwned;
	int ownedBy;
public:

	//Constructor.. Not entirely pure virtual. 
	CSquare(int code, std::string name);

	//This just returns the name of the square
	virtual std::string ReturnName() = 0;

	//LandedOn has a bunch of other functions within it when used depending on the actual square type in lands on
	//either property or special thanks to the pure virtual functions in CSquare.
	//Just make sure you put the players in order (Current Player, Other Player)
	virtual void LandedOn(CPlayer* player1, CPlayer* player2) = 0;

	//Used within the LandedOn function, no real need to use this outside that function
	virtual void Buy(CPlayer* player) = 0;

	virtual int CheckForOwnership() = 0;

	~CSquare();
};

