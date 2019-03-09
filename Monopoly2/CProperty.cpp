#include "pch.h"
#include "CProperty.h"


CProperty::CProperty(int code, std::string name, int cost, int rent, int group): CSquare(code, name)
{
	mCost = cost;
	mRent = rent;
	mGroup = group;
}

std::string CProperty::ReturnName()
{
	return mName;
}

void CProperty::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	//What happens when the player lands on a spot
	//uses either the Buy/Rent functions from CProperty/CSpecial depending on instanced item. 
	std::cout << currentPlayer->ReturnName() << " lands on: " << ReturnName() << std::endl;

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
		//Time to pay the other player
		//This bit essentially pulls the current balances of each player, and then modifies them according to the rent cost of the current square
		//after modifying the balances, uses a setter to make the player's balance set. 
		int otherPlayerBalance = otherPlayer->ReturnBalance();
		int currentPlayerBalance = currentPlayer->ReturnBalance();

		currentPlayerBalance = currentPlayerBalance - mRent;
		otherPlayerBalance = otherPlayerBalance + mRent;

		currentPlayer->AdjustBalance(currentPlayerBalance);
		otherPlayer->AdjustBalance(otherPlayerBalance);

		std::cout << currentPlayer->ReturnName() << " pays " << otherPlayer->ReturnName() << " " << mRent << std::endl;
	}
	std::cout << std::endl;
}

void CProperty::Buy(CPlayer* player)
{
	//This function only runs if the property isn't owned. 
	//Basically it sets the property's values to be owned, and who by (using player's Number)
	//then takes the cost of the property from the player's balance, then adds the position of where the player is into the player's portfolio
	int playerBalance = player->ReturnBalance();

	if (playerBalance > 0) 
	{
		ownedBy = player->ReturnPlayerNumber();
		isOwned = true;

		playerBalance = playerBalance - mCost;
		player->AdjustBalance(playerBalance);
		player->AddProperty(player->ReturnPosition());

		//Text output for verification
		std::cout << player->ReturnName() << " buys " << mName << " for " << mCost << std::endl;
		std::cout << player->ReturnName() << " now owns " << player->ReturnPortfolioSize() << " properties." << std::endl;
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
