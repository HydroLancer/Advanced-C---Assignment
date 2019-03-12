#pragma once
#include "MonopolyHeader.hpp"
class CPlayer
{
protected:
	std::string mName;
	int mBalance;
	int mPosition;
	int mPlayerNumber;
	std::vector<int> ownedProperties[26];

public:
	CPlayer(std::string name, int code);

	//Getters
	std::string ReturnName();
	int ReturnBalance();
	int ReturnPosition();
	int ReturnPlayerNumber();

	//Setters
	void AddBalance(int addition);
	void MinusBalance(int removal);
	void AddProperty(int pos);
	void SetPosition(int newPos);

	//Actual Functions
	int Roll();
	~CPlayer();
};

