#include "../include/Game_Board.h"

int
main ()
{
	Game_Board board {20, 40};

	board.init();

	board.render();
}
