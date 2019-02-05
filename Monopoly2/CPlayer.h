#pragma once
#include "MonopolyHeader.hpp"
class CPlayer
{
protected:
	std::string mName;
	int mBalance;
	int mPosition;

public:
	CPlayer(std::string name);
	~CPlayer();
};

