#include "HeartsGame.h"

int main()
{
	int numplayers = 4; //number of players
	HeartsGame game;
	game.play_Hearts(numplayers);
	std::system("pause");
	return 0;

}