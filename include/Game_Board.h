#pragma once
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <cstddef>
#include <vector>

#define GRID std::vector<std::vector<Cell_Status>>

enum Cell_Status
{
	DEAD = 0,
	ALIVE = 1,
};

class Game_Board
{
public:
	Game_Board (size_t height, size_t width);
	void print ();
	void init ();
private:
	size_t m_height;
	size_t m_width;
	GRID m_board;
};

#endif
