#include "pch.h"
#include "CAirport.h"


CAirport::CAirport(int code, std::string name) : CSquare(code, name)
{
	mCost = 200;
	mGoodsCost = 10;
}

std::string CAirport::ReturnName()
{
	return mName;
}

void CAirport::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " landed on " << mName << std::endl;
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
