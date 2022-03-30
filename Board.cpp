#include "Board.h"

Board::Board(int a)
{
	if (a < 3)
	{
		a = 3;
	}
	this->size = a * a;
	papan = new char[size];

	for (int i = 0; i < size; i++)
	{
		papan[i] = ' ';
	}
}

Board::~Board()
{
	delete[] papan;
}

int Board::getSize()
{
	return size;
}

void Board::printBoard()
{
	for (int i = 0; i < size; i++)
	{
		cout << papan[i] << ' ';
		if ((i + 1) % (int)sqrt(size) == 0)
		{
			cout << endl;
		}
	}
}

void Board::taruhSimbol(int koor, char simbol)
{
	int tempKoor = koor;
	if (!(isOccupied(koor)))
	{
		papan[koor] = simbol;
	}
	else
	{
		while (tempKoor == koor)
		{
			cout << "Sudah ditempati" << endl;
			cout << "Input : "; cin >> tempKoor;
		}
		papan[tempKoor] = simbol;
	}
	
}

bool Board::checkWin()
{
	int streak = 0;
	int vstreak = 0;
	for (int i = 0; i < size; i++)
	{
		if (papan[i] == papan[i + 1] && papan[i] != ' ')
		{
			streak += 1;
		}
		else if ((i + 1) % (int)sqrt(size) == 0)
		{
			streak = 0;
		}
		//cout << streak;
		if (streak == ((int)sqrt(size) - 1))
		{
			return 1;
			break;
		}
	}
	
	for (int i = 0; i < (int)sqrt(size); i++)
	{
		for (int j = 0; j < (int)sqrt(size); j++)
		{
			if (papan2d(i,j) == papan2d(i,j + 1) && papan2d(i,j) != ' ')
			{
				vstreak += 1;
			}

			if (vstreak == 2)
			{
				return 1;
				break;
			}
		}
		vstreak = 0;
	}

	return 0;
}

bool Board::isOccupied(int koor)
{
	return papan[koor] != ' ';
}

char Board::papan2d(int x, int y)
{
	return papan[x + (int)sqrt(size) * y];
}

void Board::clearBoard()
{
	for (int i = 0; i < size; i++)
	{
		papan[i] = ' ';
	}
}