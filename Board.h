#include <iostream>
#include <math.h>
using namespace std;

class Board
{
private:
	char *papan;
	int size;
public:
	Board();
	Board(int size);
	~Board();
	int getSize();
	void clearBoard();
	void printBoard();
	void taruhSimbol(int koor, char simbol);
	bool checkWin();
	bool isOccupied(int koor);
	char papan2d(int x, int y);
};