#pragma once
#include <boost/asio.hpp>
#include <string>
#include "chatClient.cpp"

class Game
{
public:
	Game();
	~Game();
	void sendPassedCards(int a, int b, int c);
	void sendPlayedCard(int a);
	bool doPlay = true;
	bool playRound = true;
private:
	boost::asio::ip::tcp::resolver *m_resolver;
	boost::asio::io_service io_service;
	std::thread *t;

	chat_client *chat;
	void sendMessage(char* message);
};

