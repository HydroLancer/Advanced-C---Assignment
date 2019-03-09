#include "pch.h"
#include "CPlayer.h"



CPlayer::CPlayer(std::string name, int code)
{
	mName = name;
	mBalance = 1500;
	mPosition = 0;
	mPlayerNumber = code;
}

//Getters
std::string CPlayer::ReturnName()
{
	return mName;
}
int CPlayer::ReturnBalance()
{
	return mBalance;
}
int CPlayer::ReturnPosition()
{
	return mPosition;
}
int CPlayer::ReturnPlayerNumber()
{
	return mPlayerNumber;
}
int CPlayer::ReturnPortfolioSize()
{
	return ownedProperties->size();
}

//Setters
void CPlayer::AdjustBalance(int newBalance)
{
	mBalance = newBalance;
}
void CPlayer::AddProperty(int pos)
{
	//Adds the number of the board position to the vector with the player's portfolio
	ownedProperties->push_back(pos);
}
void CPlayer::SetPosition(int newPos)
{
	mPosition = newPos;
}

//Actual Functions

int CPlayer::Roll()		//TimeToRoll
{
	//ths functions rolls a random number, then should add this onto the position currently held by the player (at mPosition)
	//If it runs over 26, goes back to zero. (GO)
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	std::cout << ReturnName() << " Rolls " << roll << std::endl;
	mPosition = mPosition + roll;

	//This bit essentially functions as a "Past Go" part of the requirement
	//It keeps going past 26, then adjusts accordingly.
	//so for example, if the player was at position 25 and rolled a 5, they'd go to 30, 
	//then this would kick in, they'd get their GO money, then be on position 3 on the board. (with index starting at 0)
	if (mPosition > 25)
	{
		mPosition -= 25;		//GO is essentially position 0 AND position 27, so if we - 27, we get 0 after a roll around if the player landed on GO.
		mBalance += 200;	
	}
	return mPosition; //For now, this would tell whatever thing to point at this specific position in the vector.
	
}

CPlayer::~CPlayer()
{
}
