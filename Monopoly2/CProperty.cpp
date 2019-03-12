#include "pch.h"
#include "CProperty.h"


CProperty::CProperty(int code, std::string name, int cost, int rent, int group): CSquare(code, name)
{
	mCost = cost;
	mRent = rent;
	mGroup = group;
}

void CProperty::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	//What happens when the player lands on a spot
	//uses either the Buy/Rent functions from CProperty/CSpecial depending on instanced item. 
	std::cout << currentPlayer->ReturnName() << " lands on: " << mName << std::endl;

	int check = CheckForOwnership(); //Check for Ownership returns 0 if it's not owned, or the owner's number if it is. 
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
		currentPlayer->MinusBalance(mRent);
		otherPlayer->AddBalance(mRent);

		std::cout << currentPlayer->ReturnName() << " pays " << otherPlayer->ReturnName() << " " << POUND << mRent << std::endl;
	}
	std::cout << std::endl;
}

void CProperty::Buy(CPlayer* player)
{
	//This function only runs if the property isn't owned. 
	//Basically it sets the property's values to be owned, and who by (using player's Number)
	//then takes the cost of the property from the player's balance, then adds the position of where the player is into the player's portfolio

	if (player->ReturnBalance() > 0) 
	{
		ownedBy = player->ReturnPlayerNumber();
		isOwned = true;

		player->MinusBalance(mCost);
		player->AddProperty(player->ReturnPosition());

		//Text output for verification
		std::cout << player->ReturnName() << " buys " << mName << " for " << POUND << mCost << std::endl;
	}
	else
	{
		//outputs that the player is too broke buy the square and just bypasses
		std::cout << player->ReturnName() << " is too broke to buy " << mName << std::endl;
	}
	
}

int CProperty::CheckForOwnership()
{
	if (isOwned)
	{
		return ownedBy;
	}
	return 0;
}

CProperty::~CProperty()
{
}
