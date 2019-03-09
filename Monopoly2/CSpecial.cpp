#include "pch.h"
#include "CSpecial.h"

CSpecial::CSpecial(int code, std::string name) : CSquare(code, name)
{

}
std::string CSpecial::ReturnName()
{
	return mName;
}

//
void CSpecial::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	int check = 0;
	int currentPlayerBalance = 0;
	int otherPlayerBalance = 0;
	//What happens when the player lands on a spot
	switch (mCode)
	{
	case 2: //Go
		std::cout << currentPlayer->ReturnName() << " lands on GO" << std::endl;
		break;

	case 3: //Airport
		check = CheckForOwnership();
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
			currentPlayerBalance = currentPlayer->ReturnBalance();
			otherPlayerBalance = otherPlayer->ReturnBalance();

			currentPlayerBalance = currentPlayerBalance - 10;
			otherPlayerBalance = otherPlayerBalance + 10;

			currentPlayer->AdjustBalance(currentPlayerBalance);
			otherPlayer->AdjustBalance(otherPlayerBalance);

			std::cout << currentPlayer->ReturnName() << " pays £10 of Goods." << std::endl;
		}
		break;

	case 4: //Bonus
	
		break;

	case 5: //Penalty
	
		break;

	case 6: //Just Visiting/Jail
		std::cout << currentPlayer->ReturnName() << " lands on Jail." << std::endl << currentPlayer->ReturnName() << " is just visiting." << std::endl;
		break;

	case 7: //Go To Jail
		//Takes 50 off the current player, sets their position to 6 (Jail/Just Visiting) 
		currentPlayerBalance = currentPlayer->ReturnBalance();
		currentPlayerBalance = currentPlayerBalance - 50;
		currentPlayer->AdjustBalance(currentPlayerBalance);
		currentPlayer->SetPosition(6);

		std::cout << currentPlayer->ReturnName() << " lands on Go To Jail" << std::endl 
			<< currentPlayer->ReturnName() << " goes to Jail" << std::endl 
			<< currentPlayer->ReturnName() << " pays £50" << std::endl;
		break;

	case 8: //Free Parking
		std::cout << currentPlayer->ReturnName() << " lands on Free Parking" << std::endl 
			<< currentPlayer->ReturnName() << " is resting" << std::endl;
		break;

	}
	std::cout << std::endl;
}

void CSpecial::Buy(CPlayer* player)
{
	//Only aiports!
	int playerBalance = player->ReturnBalance();

	if (playerBalance > 0)
	{
		playerBalance = playerBalance - 200; //Because the only special square you can buy is Airports, and they're a fixed cost. 
		isOwned = true;
		ownedBy = player->ReturnPlayerNumber();
		player->AddProperty(player->ReturnPosition());
		
		std::cout << player->ReturnName() << " buys " << mName << " for 200" << std::endl;
	}
	else
	{
		std::cout << player->ReturnName() << " cannot afford to buy " << mName << std::endl;
	}

}

int CSpecial::CheckForOwnership()
{
	if (isOwned)
	{
		return ownedBy;
	}
	return 0;
}

CSpecial::~CSpecial()
{
}
