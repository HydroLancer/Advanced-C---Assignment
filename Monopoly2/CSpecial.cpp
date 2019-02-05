#include "pch.h"
#include "MonopolyHeader.hpp"


CSpecial::CSpecial(int code, std::string name) : CSquare(code, name)
{

}
void CSpecial::Display()
{
	std::cout << mCode << " " << mName << " " << std::endl;
}

CSpecial::~CSpecial()
{
}
