//Monopoly Main. 
#include "pch.h"
#define _CRTDBG_MAP_ALLOC  

#include "MonopolyHeader.hpp"
#include <crtdbg.h>  

#include "CSquare.h"
#include "CSpecial.h"
#include "CProperty.h"
#include "CPlayer.h"
#include "CAirport.h"

void boardLoading(std::vector<CSquare*>& board);


int main()
{
	std::vector<CSquare*> board;
	boardLoading(board);
	CPlayer* playerOne = new CPlayer("Dog", 1); //instantiates 2 new players
	CPlayer* playerTwo = new CPlayer("Car", 2);
	int seed = 0;
	
	//Drags up the seed number from the seed.txt file.
	std::ifstream seedFile;
	seedFile.open("seed.txt");
	while (!seedFile.eof())
	{
		seedFile >> seed;
	}

	srand(seed); //Sets the seed to whatever was contained in seed.txt

	bool endOfGame = false;
	int round = 0;

	std::cout << "Welcome to Monopoly." << std::endl << std::endl;

	while (!endOfGame)
	{
		round++;
		
		std::cout << std::endl << "Round " << round << std::endl;
		

		//---------Player One's Turn----------------//
		std::cout << playerOne->ReturnName() << "'s Turn" << std::endl;

		//Player 1 rolls, lands on a space
		//As described in CSquare.h, LandedOn is a virtual function and reacts according to CSquare Type (either Property or Special)

		int roll = playerOne->Roll(); 
		board[roll]->LandedOn(playerOne, playerTwo);
		
		std::cout << playerOne->ReturnName() << " has " << POUND << playerOne->ReturnBalance() << std::endl << std::endl;
		std::system("pause");
		std::cout << std::endl;

		//---------Player 2's Turn------------------//
		std::cout << playerTwo->ReturnName() << "'s Turn" << std::endl;
		roll = playerTwo->Roll();
		board[roll]->LandedOn(playerTwo, playerOne);

		std::cout << playerTwo->ReturnName() << " has " << POUND << playerTwo->ReturnBalance() << std::endl << std::endl;
		std::system("pause");
		std::cout << std::endl;

		if (round >= 20)
		{
			endOfGame = true;
		}
	}
	std::cout << "Game Over!" << std::endl << std::endl;

	std::cout << playerOne->ReturnName() << " finished with " << POUND << playerOne->ReturnBalance() 
		<< " and " << playerOne->ReturnPortfolioSize() << " properties" << std::endl << std::endl;

	std::cout << playerTwo->ReturnName() << " finished with " << POUND << playerTwo->ReturnBalance() 
		<< " and " << playerTwo->ReturnPortfolioSize() << " properties" << std::endl << std::endl;

	std::system("pause");

	//delete the objects now that the program has ended
	for (int i = 0; i < board.size(); i++)
	{
		delete board[i];
	}
	board.clear();

	delete playerOne;
	delete playerTwo;
	_CrtDumpMemoryLeaks();
	return 0;

}

//Pulls the board from a txt file and loads them into appropriate classes. 
void boardLoading(std::vector<CSquare*>& board)
{
	std::ifstream inputFile;
	inputFile.open("Monopoly.txt");
	if (!inputFile)
	{
		std::cout << "Wuh oh.";
		return;
	}
	while (!inputFile.eof())
	{
		std::string tempName;		//these two are used to input filenames. Though there's probably a more efficient way.. 
		std::string nameAppend;
		int code;
		int rent;
		int cost;
		int group;
		CSquare* Square;

		inputFile >> code;

		//this bunch of ifs just checks a square's code and acts appropriately
		if (code == 1) //A property type
		{
			inputFile >> tempName;
			inputFile >> nameAppend;

			tempName = tempName + " " + nameAppend;
			inputFile >> cost;
			inputFile >> rent;
			inputFile >> group;
			Square = new CProperty(code, tempName, cost, rent, group); //Not sure if I'm doing this right??
			Square->ReturnName();
		}
		if (code == 2 || code == 4 || code == 5 || code == 6) //Special Squares (GO, Bonus, Penalty, Jail)
		{
			inputFile >> tempName;
			Square = new CSpecial(code, tempName);
			Square->ReturnName();
		}
		if (code == 3 || code == 8) //Airport or Free Parking
		{
			inputFile >> tempName;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			if (code == 3)
			{
				Square = new CAirport(code, tempName);
			}
			else 
			{
				Square = new CSpecial(code, tempName);
			}
			
			Square->ReturnName();
		}
		if (code == 7) // Go To Jail
		{
			inputFile >> tempName;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			Square = new CSpecial(code, tempName);
			Square->ReturnName();
		}
		board.push_back(Square);
	}
	//time to try file input again..
	std::cout << "Map Done!" << std::endl;
	system("pause");
}
