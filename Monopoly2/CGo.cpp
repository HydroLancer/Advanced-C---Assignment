#include "pch.h"
#include "CGo.h"


CGo::CGo(int code, std::string name) : CSquare (code, name)
{
}

//As the handling of the passing GO money is done by CPlayer::Roll() purely because you might not land on go.
//this function would only be called after the roll and movement is finished. so you might pass go but not get money if that was in here. 
//all this does is simply say the player landed on go.
void CGo::LandedOn(CPlayer* currentPlayer, CPlayer* otherPlayer)
{
	std::cout << currentPlayer->ReturnName() << " lands on " << mName << std::endl;
}

CGo::~CGo()
{
}
