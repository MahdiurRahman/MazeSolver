//MAHDIUR RAHMAN
//CSCI 235 PROFESSOR LIGORIO
//PROJECT 4: MAZE SOLVER
//THIS PROJECT CREATES AN OBJECT WHICH SOLVES MAZES
//NOVEMBER 5TH 2018

#include "MazeSolver.h"
#include <fstream>


//public

MazeSolver::MazeSolver(std::string input_file)
{
	//OPENS MAZE FILE
	std::ifstream in_stream;
	in_stream.open(input_file); //? I cannot combine line 6 and 7, why?

	//READS DIMENSIONS
	in_stream >> maze_rows_;
	in_stream >> maze_columns_;

	//PUTTING FILE INTO ARRAYS
	initializeMaze(maze_rows_, maze_columns_);
	fillMaze(in_stream);
	initializeSolution();

	//CHECK IF MAZE OKAY
	if (mazeIsReady())
	{
		return;
	}
	else
	{
		std::cout << "Cannot read from input_file_name" << std::endl;
	}
}

MazeSolver::~MazeSolver()
{
	//DEALLOCATES MAZE
	for (int i = 0; i < maze_rows_; i++)
	{
		delete maze_[i];
	}
	delete maze_;

	//DEALLOCATES SOLUTION
	for (int i = 0; i < maze_rows_; i++)
	{
		delete solution_[i];
	}
	delete solution_;
}

bool MazeSolver::mazeIsReady()
{
	//CHECKS IF MAZE HAS 2 DIMENSIONS
	if ((maze_rows_ > 0) and (maze_columns_ > 0))
	{
		return true;
	}
	else return false;
}

bool MazeSolver::solveMaze()
{
	//SET UP ITERATOR/PATHFINDER (CALLED CURRENT)
	Position current;
	current.row = 0; current.column = 0;
	backtrack_stack_.push(current);

	//PERFORM PATHFINDING
	while (!backtrack_stack_.empty())
	{
		current = backtrack_stack_.top(); //current always updated at BEGINNING of loop

		//Success
		if (maze_[current.row][current.column] == '$')
		{
			std::cout << "Found the exit!!!";
			return true;
		}
		//Advance
		else if (isExtensible(current, SOUTH) or isExtensible(current, EAST))
		{
			maze_[current.row][current.column] = '>';
			solution_[current.row][current.column] = '>';
			extendPath(current);
		}
		//Retreat
		else
		{
			maze_[current.row][current.column] = 'X';
			solution_[current.row][current.column] = '@';
			backtrack_stack_.pop();
		}
	}

	//FAILURE MESSAGE
	if (backtrack_stack_.empty())
	{
		std::cout << std::endl << "This maze has no solution." << std::endl;
		return false;
	}
	return false; //for some reason, GradeScope required this
}

void MazeSolver::printSolution()
{
	std::cout << "The solution to this maze is:" << std::endl;
	for (int i = 0; i < maze_rows_; i++)
	{
		for (int j = 0; j < maze_columns_; j++)
		{
			std::cout << solution_[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}



//private

void MazeSolver::initializeMaze(int rows, int columns)
{
	maze_ = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		maze_[i] = new char[columns];
	}
}

void MazeSolver::fillMaze(std::ifstream& input_stream)
{
	for (int i = 0; i < maze_rows_; i++)
	{
		for (int j = 0; j < maze_columns_; j++)
		{
			input_stream >> maze_[i][j];
		}
	}
}

void MazeSolver::initializeSolution()
{
	solution_ = new char*[maze_rows_];
	for (int i = 0; i < maze_rows_; i++)
	{
		solution_[i] = new char[maze_columns_];
	}
	copyMazetoSolution();
}

void MazeSolver::copyMazetoSolution()
{
	for (int i = 0; i < maze_rows_; i++)
	{
		for (int j = 0; j < maze_columns_; j++)
		{
			solution_[i][j] = maze_[i][j];
		}
	}
}

bool MazeSolver::extendPath(Position current_position)
{
	Position S, E; //used as dummies so current_position is not modified

	if (isExtensible(current_position, SOUTH))
	{
		S = getNewPosition(current_position, SOUTH);
		backtrack_stack_.push(S);
	}
	if (isExtensible(current_position, EAST))
	{
		E = getNewPosition(current_position, EAST);
		backtrack_stack_.push(E);
	}
	return true;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir)
{
	if (dir == SOUTH)
	{
		old_position.row++;
	}
	else if (dir == EAST)
	{
		old_position.column++;
	}
	return old_position;
}

bool MazeSolver::isExtensible(Position current_position, direction dir)
{
	if (dir == SOUTH)
	{
		if (current_position.row < maze_rows_ - 1) //checks if current_position is at edge of maze
		{
			current_position = getNewPosition(current_position, SOUTH);
			if ((maze_[current_position.row][current_position.column] == '_') or (maze_[current_position.row][current_position.column] == '$'))
			{
				return true;
			}
		}
	}
	else if (dir == EAST)
	{
		if (current_position.column < maze_columns_ - 1) //checks if current_position is at edge of maze
		{
			current_position = getNewPosition(current_position, EAST);
			if ((maze_[current_position.row][current_position.column] == '_') or (maze_[current_position.row][current_position.column] == '$'))
			{
				return true;
			}
		}
	}
	return false;
}