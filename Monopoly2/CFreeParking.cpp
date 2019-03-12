#include "pch.h"
#include "CFreeParking.h"


CFreeParking::CFreeParking(int code, std::string name) : CSquare(code, name)
{
}

//pretty simple, really..
void CFreeParking::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
		std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl
		<< currentPlayer->ReturnName() << " is resting" << std::endl;
}

CFreeParking::~CFreeParking()
{
}
