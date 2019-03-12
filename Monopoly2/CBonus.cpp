#include "pch.h"
#include "CBonus.h"


CBonus::CBonus(int code, std::string name) : CSquare(code, name)
{

}

//Bonus panels work by simply adding some kind of money to the player's balance
//when it's landed on, it rolls its own dice to determine which bonus card to use.
void CBonus::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl;
	int chance = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
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
	}
	std::cout << currentPlayer->ReturnName() << " now has " << POUND << currentPlayer->ReturnBalance() << std::endl;
	
}

CBonus::~CBonus()
{
}
