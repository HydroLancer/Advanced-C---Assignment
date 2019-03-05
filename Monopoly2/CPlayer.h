#pragma once
#include "MonopolyHeader.hpp"
class CPlayer
{
protected:
	std::string mName;
	int mBalance;
	int mPosition;
	CSquare* ownedProperties[26];

public:
	CPlayer(std::string name);
	std::string DisplayName();
	int DisplayBalance();
	int ReturnPosition();
	int Roll();
	~CPlayer();
};

