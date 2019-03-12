#include "pch.h"
#include "CAirport.h"


CAirport::CAirport(int code, std::string name) : CSquare(code, name)
{
	mCost = 200;
	mGoodsCost = 10;
}

//Works a bit like in CProperty, but the way the "rent" works is just a set £10 no matter what.
//It simply checks to make sure it's not owned. If it isn't, the Buy() function sets the isOwned and ownedBy to true/player number
//if it is owned, it checks who by (even though for the moment it's only 2 players) and pays rent accordingly. 
void CAirport::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl;
	int check = CheckForOwnership();
	if (check == 0)
	{
		Buy(currentPlayer);
	}
	else if (check == currentPlayer->ReturnPlayerNumber())
	{
		std::cout << "Nothing Happens" << std::endl;
	}
	else
	{
		currentPlayer->MinusBalance(mGoodsCost);
		otherPlayer->AddBalance(mGoodsCost);

		std::cout << currentPlayer->ReturnName() << " pays " << otherPlayer->ReturnName() << " " << POUND << mGoodsCost << " of Goods." << std::endl;
	}
}

//Sets isOwned and ownedBy as described above, takes money off the player, adds the property to the player's portfolio.
void CAirport::Buy(CPlayer* player)
{
	if (player->ReturnBalance() > 0)
	{
		player->MinusBalance(mCost);
		isOwned = true;
		ownedBy = player->ReturnPlayerNumber();
		player->AddProperty(player->ReturnPosition());

		std::cout << player->ReturnName() << " buys " << mName << " for " << POUND << mCost << std::endl;
	}
	else
	{
		std::cout << player->ReturnName() << " cannot afford to buy " << mName << std::endl;
	}
}

//Returns either 0 (not owned) or (currently) 1 or 2 depending on who owns it.
int CAirport::CheckForOwnership()
{
	if (isOwned)
	{
		return ownedBy;
	}
	return 0;
}

CAirport::~CAirport()
{
}
