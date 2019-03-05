//Monopoly Main. 
#include "pch.h"
#include "MonopolyHeader.hpp"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

void boardLoading(std::vector<CSquare*>& board);


int main()
{
	std::vector<CSquare*> board;
	boardLoading(board);
	CPlayer* playerOne = new CPlayer("Dog"); //instantiates 2 new players
	CPlayer* playerTwo = new CPlayer("Car");

	srand(4); //Sets the seed to 4.

	bool endOfGame = false;
	int round = 0;

	std::cout << "Welcome to Monopoly." << std::endl << std::endl;

	while (!endOfGame)
	{
		round++;

		std::cout << playerOne->DisplayName() << "'s Turn" << std::endl;

		std::system("pause");
		//generate random number here (Function in CPlayer Class..)
		//Display number

		////////////////////
		//actual game here//
		////////////////////

		if (round <= 20)
		{
			endOfGame = true;
		}
	}
	std::cout << "Game Over!" << std::endl;

	//delete the objects now that the program has ended
	for (int i = 0; i < board.size(); i++)
	{
		delete board[i];
	}
	board.clear();
	_CrtDumpMemoryLeaks();
	return 0;

}

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
		if (code == 1)
		{
			inputFile >> tempName;
			inputFile >> nameAppend;

			tempName = tempName + " " + nameAppend;
			inputFile >> cost;
			inputFile >> rent;
			inputFile >> group;
			Square = new CProperty(code, tempName, cost, rent, group); //Not sure if I'm doing this right??
			Square->Display();
		}
		if (code == 2 || code == 4 || code == 5 || code == 6)
		{
			inputFile >> tempName;
			Square = new CSpecial(code, tempName);
			Square->Display();
		}
		if (code == 3 || code == 8)
		{
			inputFile >> tempName;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			Square = new CSpecial(code, tempName);
			Square->Display();
		}
		if (code == 7)
		{
			inputFile >> tempName;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			Square = new CSpecial(code, tempName);
			Square->Display();
		}
		board.push_back(Square);
	}
	//time to try file input again..
	std::cout << "Map Done!" << std::endl;
	system("pause");
}
