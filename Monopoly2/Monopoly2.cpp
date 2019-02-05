//Monopoly Main. 
#include "pch.h"
#include "MonopolyHeader.hpp"

void boardLoading(std::vector<CSquare*>& board);

int main()
{
	std::vector<CSquare*> board;
	boardLoading(board);

	return 0;

}

void boardLoading(std::vector<CSquare*>& board)
{
	int code;

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
	std::cout << "Map Done!";
	system("pause");
}
