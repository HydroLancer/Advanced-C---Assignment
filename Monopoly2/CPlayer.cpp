#include "pch.h"
#include "MonopolyHeader.hpp"


CPlayer::CPlayer(std::string name)
{
	mName = name;
	mBalance = 1500;
	mPostion = 0;
}


CPlayer::~CPlayer()
{
}
