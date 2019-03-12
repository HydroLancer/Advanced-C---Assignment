#include "pch.h"
#include "CGoToJail.h"


CGoToJail::CGoToJail(int code, std::string name) : CSquare(code, name)
{
}

//Takes 50 off the current player, sets their position to 6 (Jail/Just Visiting) 
void CGoToJail::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	
	currentPlayer->MinusBalance(50);
	currentPlayer->SetPosition(6);

	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl
		<< currentPlayer->ReturnName() << " goes to Jail" << std::endl
		<< currentPlayer->ReturnName() << " pays " << POUND << "50" << std::endl;
}

CGoToJail::~CGoToJail()
{
}
