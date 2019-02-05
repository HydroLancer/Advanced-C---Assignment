#pragma once
#include "MonopolyHeader.hpp"

class CSquare
{
private:
	int mCode;
	std::string mName;

public:
	CSquare(int code, std::string name);
	void Display();
	~CSquare();
};

