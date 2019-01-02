#include <iostream>
#include "MazeSolver.h"

#include <fstream>
#include <string>
using namespace std;

int main()
{
	/*ifstream in;
	in.open("maze.txt");
	char* dum = new char[10];
	for (int i = 0; i < 10; i++)
	{
		in >> dum[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cout << dum[i];
	}
	cin >> dum;*/

	MazeSolver solver("maze.txt");
	if (solver.mazeIsReady())
	{
		solver.solveMaze();
		solver.printSolution();
	}

	int x; cin >> x;
	return 0;
}