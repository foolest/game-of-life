#include "../include/Game_Board.h"
#include <cstddef>
#include <cstdio>
#include <random>

Game_Board::Game_Board (size_t height, size_t width)
{
	m_height = height;
	m_width = width;

	std::vector<Cell_Status> v (width, Cell_Status::DEAD);

	for (size_t i{0}; i < height; i++)
		m_board.push_back(v);
}

void
Game_Board::print ()
{
	for (std::vector<Cell_Status> row : m_board)
	{
		for (Cell_Status x : row)
			printf("%i", x);
		printf("\n");
	}
}

void
Game_Board::init ()
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
