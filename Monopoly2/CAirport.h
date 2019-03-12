#pragma once
#include "CSquare.h"
class CAirport :
	public CSquare
{
protected:
	int mCost;
	int mGoodsCost;

public:
	CAirport(int code, std::string name);

	//LandedOn has a bunch of other functions within it when used depending on the actual square type in lands on
	//either property or special thanks to the pure virtual functions in CSquare.
	//Just make sure you put the players in order (Current Player, Other Player)
	void LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer);

	//Used within the LandedOn function, no real need to use this outside that function
	void Buy(CPlayer* player);

	int CheckForOwnership();
	~CAirport();
};

