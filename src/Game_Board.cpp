#include "../include/Game_Board.h"
#include <cstddef>
#include <cstdio>
#include <random>
#include <vector>

Game_Board::Game_Board (size_t height, size_t width)
{
	m_height = height;
	m_width = width;

	std::vector<Cell_Status> v (width, Cell_Status::DEAD);

	for (size_t i{0}; i < height; i++)
		m_board.push_back(v);
}

void
Game_Board::render ()
{
	for (std::vector<Cell_Status> row : m_board)
	{
		for (Cell_Status x : row)
		{
			if (x == Cell_Status::ALIVE)
				printf("█");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("----------------------------------------------------------------\n");
}

void
Game_Board::init_random ()
{
	std::mt19937 mt {std::random_device{}()};
	std::uniform_int_distribution<> liveness {0, 1};

	for (size_t i {0}; i < m_height; i++)
		for (size_t j {0}; j < m_width; j++)
		{
			if (liveness(mt) == 1) m_board[i][j] = Cell_Status::ALIVE;
			else continue;
		}
}

void
Game_Board::next_board (const GRID past_board)
{
	for (size_t i{0}; i < m_height; i++)
		for (size_t j{0}; j < m_width; j++)
		{
			if (is_liveble(past_board, i, j))
				m_board[i][j] = Cell_Status::ALIVE;

			else 
				m_board[i][j] = Cell_Status::DEAD;
		}
}

std::vector<Cell_Status>
Game_Board::get_neighbors (const GRID& board, size_t i, size_t j)
{
	std::vector<Cell_Status> neighbors;
	if (i > 0)
	{
		if (j > 0) neighbors.push_back(board[i-1][j-1]);
		neighbors.push_back(board[i-1][j]);
		if (j < m_width - 1) neighbors.push_back(board[i-1][j+1]);
	}
	if (i < m_height - 1)
	{
		if (j > 0) neighbors.push_back(board[i+1][j-1]);
		neighbors.push_back(board[i+1][j]);
		if (j < m_width - 1) neighbors.push_back(board[i+1][j+1]);
	}
	if (j > 0) neighbors.push_back(board[i][j-1]);
	if (j < m_width - 1) neighbors.push_back(board[i][j+1]);

	return neighbors;
}

bool
Game_Board::is_liveble (const GRID& past_board, size_t i, size_t j)
{
	int alives_count{0};
	for (Cell_Status x : get_neighbors(past_board, i, j))
		if (x == Cell_Status::ALIVE) alives_count++; 
	
	if (past_board[i][j] == Cell_Status::DEAD)
	{
		if (alives_count == 3) return true;
		else return false;
	}
	else 
	{
		if (alives_count <= 1 || alives_count > 3) return false;
		else return true;
	}
}

GRID
Game_Board::get_board ()
{
	return m_board;
}
