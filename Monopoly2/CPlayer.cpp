#include "pch.h"
#include "MonopolyHeader.hpp"


CPlayer::CPlayer(std::string name)
{
	mName = name;
	mBalance = 1500;
	mPosition = 0;
}
std::string CPlayer::DisplayName()
{
	return mName;
}
int CPlayer::DisplayBalance()
{
	return mBalance;
}

int CPlayer::ReturnPosition()
{
	return mPosition;
}

int CPlayer::Roll()		//TimeToRoll
{
	//possibly add more here? Maybe consolidate roll into a movement function (aka move to currentPosition + whatever rolled)
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

CPlayer::~CPlayer()
{
}
