//Monopoly Main. 
#include "pch.h"
#define _CRTDBG_MAP_ALLOC  

#include "MonopolyHeader.hpp"
#include <crtdbg.h>  
#include "AllTheClasses.h"


void boardLoading(std::vector<CSquare*>& board);
int Run()
{
	std::vector<CSquare*> board;
	boardLoading(board);
	CPlayer* playerOne = new CPlayer("Dog", 1); //instantiates 2 new players
	CPlayer* playerTwo = new CPlayer("Car", 2);
	int seed = 0;

	//Drags up the seed number from the seed.txt file.
	std::ifstream seedFile;
	seedFile.open("seed.txt");
	if (!seedFile)
	{
		std::cout << "Cannot find seed file" << std::endl;
		std::system("pause");
		return 0;
	}
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
		
		//---------Player One's Turn----------------//

		/*Bit complex.
		The best way to describe how this works is: Cplayer::Roll() returns where the player is currently positioned.
		within Roll(), it calculates the current position + what the player rolled, then returns the new position
		So as a result, the below line accesses a single square and runs the virtual method which differs between each instanced class.*/
		board[playerOne->Roll()]->LandedOn(playerOne, playerTwo);

		std::cout << playerOne->ReturnName() << " has " << POUND << playerOne->ReturnBalance() << std::endl << std::endl;

		//---------Player 2's Turn------------------//

		board[playerTwo->Roll()]->LandedOn(playerTwo, playerOne);

		std::cout << playerTwo->ReturnName() << " has " << POUND << playerTwo->ReturnBalance() << std::endl << std::endl;

		if (round >= 20)
		{
			endOfGame = true;
		}
	}
	std::cout << "Game Over!" << std::endl << std::endl;


	std::system("pause");

	//delete the objects now that the program has ended
	for (int i = 0; i < board.size(); i++)
	{
		delete board[i];
	}
	board.clear();

	delete playerOne;
	delete playerTwo;
}

int main()
{
	Run();
	_CrtDumpMemoryLeaks();
	return 0;

}

//Pulls the board from a txt file and loads them into appropriate classes.
//Simply uses the code from the start of each line to determine what the square actually should be using the CSquare Constructor to add in codes and names
//for Property, further parameters are passed in for CProperty's constructor which has their own data members.
//then instances a new derived class using an almost entirely abstract class CSquare
//After it's created the class, it then puts it into the 'board' vector, ready for the game to run.
void boardLoading(std::vector<CSquare*>& board)
{
	std::ifstream inputFile;
	inputFile.open("Monopoly.txt");
	if (!inputFile)
	{
		std::cout << "Monopoly.txt not found";
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
		CSquare* Square; //Abstract class, ready for getting a new derived class to be loaded. 

		inputFile >> code;

		//this bunch of ifs just checks a square's code and acts appropriately
		//these are split up because of the way the names work. Some are 2 words, some are 3 words, some are just 1 word. 
		if (code == 1) //A property type
		{
			inputFile >> tempName;
			inputFile >> nameAppend;

			tempName = tempName + " " + nameAppend;
			inputFile >> cost;
			inputFile >> rent;
			inputFile >> group;
			Square = new CProperty(code, tempName, cost, rent, group);
		}
		else if (code == 2 || code == 4 || code == 5 || code == 6) //Special Squares (GO, Bonus, Penalty, Jail)
		{
			inputFile >> tempName;
			switch (code)
			{
			case 2:
				Square = new CGo(code, tempName);
				break;
			case 4:
				Square = new CBonus(code, tempName);
				break;
			case 5:
				Square = new CPenalty(code, tempName);
				break;
			case 6:
				Square = new CJustVisiting(code, tempName);
				break;
			}
		}
		else if (code == 3 || code == 8) //Airport or Free Parking
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
				Square = new CFreeParking(code, tempName);
			}
		}
		else if (code == 7) // Go To Jail
		{
			inputFile >> tempName;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			inputFile >> nameAppend;
			tempName = tempName + " " + nameAppend;
			Square = new CGoToJail(code, tempName);
		}

		//Now the class has been set up, stick the square onto the board. 
		board.push_back(Square);
	}
}
