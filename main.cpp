//MAHDIUR RAHMAN 
//PROJECT 9 MAP GAME
//
#include <iostream>
#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

//execution function
void execute(string& s)
{
	Map map(s);
	while (!map.endgame())
	{
		map.Show();
		map.Set();
	}
	map.Show();
}

int main()
{
	string s;
	cout << "Hey, welcome to the MAPGAME!\n\nTo start, type the filename and press enter: ";
	cin >> s;

	//begins execution of game
	execute(s);

	int b;
	cout << endl << "Enter any key, then press enter to exit: ";
	cin >> b;

	return 0;
}