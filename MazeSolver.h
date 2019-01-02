//
//  MazeSolver.h
//
//  Maze:
//  This class finds a solution to a maze read from an input file
//  and prints a solution to the standard output
//
//  Created by Tiziana Ligorio on 10/1/18.
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//

#ifndef MAZE_SOLVER_H_
#define MAZE_SOLVER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <stack>

enum direction { SOUTH, EAST };

struct Position
{
	int row;
	int column;
};

class MazeSolver
{
public:

	MazeSolver(std::string input_file);
	~MazeSolver();
	bool mazeIsReady();
	bool solveMaze();
	void printSolution();

private:

	//PRIVATE DATA MEMBERS:

	int maze_rows_ = 0;             //the number of rows as read from input file
	int maze_columns_ = 0;          //the number of columns as read from input file
	bool maze_ready = false;        //indicates whether the maze has been initialized from input file
	char** maze_ = nullptr;       //a 2-d character array containing maze characters read from input file
	char** solution_ = nullptr;   //a 2-d character array containing maze characters copied from maze_
								  // and path to exit marked with '>' characters and position backtracked from marked with '@'characters
	std::stack<Position> backtrack_stack_;  

	void initializeMaze(int rows, int columns);
	void fillMaze(std::ifstream& input_stream);
	void initializeSolution();
	void copyMazetoSolution();

	//functions used by solveMaze() to solve
	bool extendPath(Position current_position);
	Position getNewPosition(Position old_position, direction dir);
	bool isExtensible(Position current_position, direction dir);


}; // end MazeSolver

#endif /* MAZE_SOLVER_H_ */