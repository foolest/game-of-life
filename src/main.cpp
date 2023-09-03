#include "../include/Game_Board.h"
#include <chrono>
#include <thread>


int
main ()
{
	Game_Board board {20, 50};
	
	board.init_random();
	board.render();
	while(true)
	{
		board.next_board(board.get_board());
		board.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

}
