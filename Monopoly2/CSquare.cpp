#include "pch.h"
#include "CSquare.h"

CSquare::CSquare(int code, std::string name)
{
	mCode = code;
	mName = name;
	isOwned = false;
}

CSquare::~CSquare()
{

}
