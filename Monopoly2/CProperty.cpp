#include "pch.h"
#include "MonopolyHeader.hpp"


CProperty::CProperty(int code, std::string name, int cost, int rent, int group): CSquare(code, name)
{
	mCost = cost;
	mRent = rent;
	mGroup = group;
}

void CProperty::Display()
{
	std::cout << mCode << " " << mName << " " << mCost << " " << mRent << " " << mGroup << std::endl;
}

CProperty::~CProperty()
{
}
