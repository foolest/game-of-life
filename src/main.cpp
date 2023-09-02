#include "../include/Game_Board.h"

int
main ()
{
	Game_Board board {5, 5};

	board.init();

	board.print();
}
