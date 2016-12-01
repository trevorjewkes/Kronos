#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	Game hearts;
	int a, b, c;
	while (hearts.doPlay)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		hearts.sendPassedCards(a, b, c);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		while (hearts.playRound)
		{
			std::cin >> a;
			hearts.sendPlayedCard(a);
			//std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
	return 0;
}