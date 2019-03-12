#include "pch.h"
#include "CPenalty.h"


CPenalty::CPenalty(int code, std::string name) : CSquare(code, name)
{
}

//Just like in CBonus - The function rolls its own dice and decides which card to use based on that.
//instead of a nice cash money bonus, the player gets it taken off them.
void CPenalty::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl;
	int chance = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
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
	}
}

CPenalty::~CPenalty()
{
}
