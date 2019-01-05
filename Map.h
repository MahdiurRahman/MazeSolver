//MAHDIUR RAHMAN
//PROJECT 9: MAP GAME
#ifndef MAP
#define MAP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;

typedef vector<vector<char>> _2d;
typedef vector<char> _1d;

class Map
{
	public:
		//CONSTRUCTORS
		Map(const string& file);
		Map() : length{ 0 }, width{ 0 }, x{ 0 }, y{ 0 }, d{ '\0' }, score{ 0 }, target{ 0 } {};

		//PBLC FUNCTIONS
		bool endgame();
		void Set();
		void Show();

		//DESTRUCTOR
		~Map();

	private:

		//PVT VARIABLES
		int length; //length of map:Y
		int width; //width of map:X
		_2d game; //map 2d array
		int x; int y; //user's x and y
		char d; //wasd selection
		int score; //# of $ gained
		int target; //# of $ to win

		//PVT FUNCTIONS
		void target_score(); //set up 'target' variable
		void Display(const int&, const int&, const int&, const int&); //Displays 9 by 9 portion of map
		void check_wasd(const int&, const int&); //validity of wasd selection
		void move_wasd(const int&, const int&); //actually move player
};

#endif