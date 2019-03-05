#include "pch.h"
#include "MonopolyHeader.hpp"


CSquare::CSquare(int code, std::string name)
{
	mCode = code;
	mName = name;
	isOwned = false;
}

void CSquare::Display()
{
	std::cout << mCode << " " << mName << std::endl;
}


CSquare::~CSquare()
{
}
