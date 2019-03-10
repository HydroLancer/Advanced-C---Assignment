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
void CPlayer::AddBalance(int addition)
{
	mBalance = mBalance + addition;
}

void CPlayer::MinusBalance(int removal)
{
	mBalance = mBalance - removal;
}

//Adds the position of the owned property into a vector. 
void CPlayer::AddProperty(int pos)
{
	//Adds the number of the board position to the vector with the player's portfolio
	ownedProperties->push_back(pos);
}

//Pretty much only used in CSpecial::LandedOn() to force the player to move from Go To Jail to Jail.
void CPlayer::SetPosition(int newPos)
{
	mPosition = newPos;
}

//Actual Functions

//ths functions rolls a random number, then should add this onto the position currently held by the player (at mPosition)
//If it runs over 26, goes back to zero. (GO)
int CPlayer::Roll()		//TimeToRoll
{
	
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	std::cout << ReturnName() << " Rolls " << roll << std::endl;
	mPosition = mPosition + roll;

	//This bit essentially functions as a "Past Go" part of the requirement
	//It keeps going past 26, then adjusts accordingly.
	//so for example, if the player was at position 25 and rolled a 5, they'd go to 30, 
	//then this would kick in, they'd get their GO money, then be on position 3 on the board. (with index starting at 0)
	if (mPosition > 25)
	{
		mPosition -= 26;		//GO is essentially position 0 AND position 26, so if we - 26, we get 0 after a roll around if the player landed on GO.
		mBalance += 200;
		std::cout << mName << " passes GO and collects " << POUND << "200" << std::endl;
	}

	return mPosition; //when used like board[player->Roll()]->LandedOn(PlayerOne, PlayerTwo) - It will use the appropriate function
	
}

CPlayer::~CPlayer()
{
}
