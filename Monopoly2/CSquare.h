#pragma once
#include "MonopolyHeader.hpp"

class CSquare
{
protected:
	int mCode;
	std::string mName;
public:
	CSquare(int code, std::string name);
	virtual void Display();
	~CSquare();
};

