//MAHDIUR RAHMAN PROJECT 9 MAP GAME implementation
#include "Map.h"


//1. CREATION
	//Map constructor
	Map::Map(const string& file)
	{
		ifstream fs(file);
		string dum;

		//set up dimensions of 2d
		fs >> width >> length;

		//set up space AND contents of 2d
		getline(fs, dum);
		for (int i = 0; i < length; i++)
		{
			_1d row;
			getline(fs, dum);
			for (int j = 0; j < width; j++)
			{
				row.push_back(dum[j]);
			}
			game.push_back(row);
		}

		//INITIALIZATIONS
		y = 1; x = 1; //user position
		game[y][x] = '@'; //user avatar
		d = '\0'; //reset directional (d) key
		score = 0; //reset score
		target = 0;  target_score(); //call to func sets up target variable
	}

	//sets target score for end game
	void Map::target_score()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (game[i][j] == '$')
				{
					target++;
				}
			}
		}
	}

	//tests if score has reached target
	bool Map::endgame()
	{
		if (score == target)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


//2. CAMERA
	//Decides how to set up Display function (what paramters to put)
	void Map::Show()
	{
		system("CLS"); //NOTE: for visual studio I have to use "CLS" and not "clear"

		//Intro
		cout << ">>>>>> MAPGAME <<<<<<\n\nUse w, a, s, d to get all the $ signs!\n(press enter after direction)\n\nScore: " << score << "/" << target << "\n\n";

		//Middle section (where camera is centered on player)
		if (((y > 3) and (y < (length - 4))) and ((x > 3) and (x < (width - 4))))
		{
			Display(y - 4, y + 4, x - 4, x + 4);
		}
		//1 upper left corner
		else if ((y < 4) and (x < 4))
		{
			Display(0, 9, 0, 9);
		}
		//2 upper right corner
		else if ((y < 4) and (x > (width - 5)))
		{
			Display(0, 9, width - 9, width);
		}
		//3 lower right corner
		else if ((y > (length - 5)) and (x > (width - 5)))
		{
			Display(length - 9, length, width - 9, width);
		}
		//4 lower left corner
		else if ((y > (length - 5)) and (x < 4))
		{
			Display(length - 9, length, 0, 9);
		}
		//5 upper edge
		else if ((y < 4) and ((x > 3) and (x < (width - 4))))
		{
			Display(0, 9, x - 4, x + 4);
		}
		//6 right edge
		else if (((y > 3) and (y < (length - 4))) and (x>(width-5)))
		{
			Display(y - 4, y + 4, width - 9, width);
		}
		//7 bottom edge
		else if ((y > (length - 5)) and ((x > 3) and (x < (width - 4))))
		{
			Display(length - 9, length, x - 4, x + 4);
		}
		//8 left edge
		else if (((y > 3) and (y < (length - 4))) and (x < 4))
		{
			Display(y - 4, y + 4, 0, 9);
		}
	}

	//Actually displays map based on parameters for 2 for-loops
	void Map::Display(const int& a, const int& b, const int& c, const int& d)
	{
		cout << '\n';
		//1st for-loop for y-axis
		for (int i = a; i < b; i++)
		{
			//2nd for-loop for x-axis
			for (int j = c; j < d; j++)
			{
				cout << game[i][j];
			}
			cout << '\n';
		}
	}


//3. MOVEMENT
	//takes in the wasd value for user
	void Map::Set()
	{
		cout << "Enter: ";
		d = _getch();
		//cin >> d;
		//for wasd controls
		if ((d == 'w'))
		{
			check_wasd((y - 1), x);
		}
		else if ((d == 'a'))
		{
			check_wasd(y, (x - 1));
		}
		else if ((d == 's'))
		{
			check_wasd((y + 1), x);
		}
		else if ((d == 'd'))
		{
			check_wasd(y, (x + 1));
		}
		//2. else nothing
		else
		{
			return;
		}
	}

	//check if WASD movement is allowed
	void Map::check_wasd(const int& Y, const int& X)
	{
		//1. check movement within bounds of map
		if ((Y > -1) and (Y < length) and (X > -1) and (X < width))
		{
			//2. if movement to empty space
			if (game[Y][X] == ' ')
			{
				move_wasd(Y, X);
			}
			//3. if movement to point '$'
			else if (game[Y][X] == '$')
			{
				move_wasd(Y, X);
				score++; //score raise
			}
		}
		//4. else nothing
		else
		{
			return;
		}
	}

	//actually perform movement
	void Map::move_wasd(const int& Y, const int& X)
	{
		game[y][x] = ' ';
		game[Y][X] = '@';
		y = Y;
		x = X;
	}


//4. DESTRUCTION
	Map::~Map()
	{
		cout << "\nYou've won! Hurray!\n";
	}