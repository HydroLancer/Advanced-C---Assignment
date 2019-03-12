#include "pch.h"
#include "CJustVisiting.h"


CJustVisiting::CJustVisiting(int code, std::string name) : CSquare (code, name)
{
}

//Just like free parking! Just simply outputs the resting. 
void CJustVisiting::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl << currentPlayer->ReturnName() << " is just visiting." << std::endl;
}

CJustVisiting::~CJustVisiting()
{
}
