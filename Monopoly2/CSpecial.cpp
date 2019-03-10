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
	int chance = 0;
	//What happens when the player lands on a spot
	switch (mCode)
	{
	case 2: //Go
		//The handling of money being given for landing on GO is in CPlayer::Roll()
		//as it's not guaranteed to land on go every time but you still need to get that cash moneys. 
		std::cout << currentPlayer->ReturnName() << " lands on GO" << std::endl;
		break;

	case 4: //Bonus
	
		std::cout << currentPlayer->ReturnName() << " lands on Bonus.." << std::endl;

		chance = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
		switch (chance)
		{
		case 1:
			//Player finds £20 on the ground
			std::cout << "Find some Money. Player gains " << POUND << "20" << std::endl;
			currentPlayer->AddBalance(20);
			break;

		case 2:
			//Player wins a competition
			std::cout << "Win Competition. Player gains " << POUND << "50" << std::endl;
			currentPlayer->AddBalance(50);
			break;

		case 3:
			//Tax Rebate
			std::cout << "Tax Rebate. Player gains " << POUND << "100" << std::endl;
			currentPlayer->AddBalance(100);
			break;

		case 4:
			//Win Lottery
			std::cout << "Lottery Win. Player gains " << POUND << "150" << std::endl;
			currentPlayer->AddBalance(150);
			break;

		case 5:
			//Bequest.
			std::cout << "Bequest. Player gains " << POUND << "200" << std::endl;
			currentPlayer->AddBalance(200);
			break;

		case 6:
			//Birthday!
			std::cout << "Birthday. Player gains " << POUND << "300" << std::endl;
			currentPlayer->AddBalance(300);
			break;

		default:
			//shouldn't happen, but to be safe..
			std::cout << "Wuh oh, it broke." << std::endl << std::endl;
			break;
		}
		std::cout << currentPlayer->ReturnName() << " now has " << POUND << currentPlayer->ReturnBalance() << std::endl;
		break;

	case 5: //Penalty
		std::cout << currentPlayer->ReturnName() << " lands on Penalty.." << std::endl;
		chance = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
		switch (chance)
		{
		case 1:
			//Pay food bill
			std::cout << "Pay food bill. Player loses " << POUND << "20" << std::endl;
			currentPlayer->MinusBalance(20);
			break;

		case 2:
			//Phone bill
			std::cout << "Pay phone bill. Player loses " << POUND << "50" << std::endl;
			currentPlayer->MinusBalance(50);
			break;

		case 3:
			//Heating Bill
			std::cout << "Pay heating bill. Player loses " << POUND << "100" << std::endl;
			currentPlayer->MinusBalance(100);
			break;

		case 4:
			//Vehicle Tax
			std::cout << "Pay vehicle tax. Player loses " << POUND << "150" << std::endl;
			currentPlayer->MinusBalance(150);
			break;

		case 5:
			//Fuel Bill
			std::cout << "Pay fuel bill. Player loses " << POUND << "200" << std::endl;
			currentPlayer->MinusBalance(200);
			break;

		case 6:
			//Windfall Tax
			std::cout << "Pay Windfall Tax. Player loses " << POUND << "300" << std::endl;
			currentPlayer->MinusBalance(300);
			break;

		default:
			break;
		}
		break;

	case 6: //Just Visiting/Jail
		std::cout << currentPlayer->ReturnName() << " lands on Jail." << std::endl << currentPlayer->ReturnName() << " is just visiting." << std::endl;
		break;

	case 7: //Go To Jail
		//Takes 50 off the current player, sets their position to 6 (Jail/Just Visiting) 
		currentPlayer->MinusBalance(50);
		currentPlayer->SetPosition(6);

		std::cout << currentPlayer->ReturnName() << " lands on Go To Jail" << std::endl 
			<< currentPlayer->ReturnName() << " goes to Jail" << std::endl 
			<< currentPlayer->ReturnName() << " pays " << POUND << "50" << std::endl;
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
	//You Can't buy Special Squares. 
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
