#include "Game.h"



Game::Game()
{
	m_resolver = new boost::asio::ip::tcp::resolver(io_service);
	auto endpoint_iterator = m_resolver->resolve({ "192.168.1.102", "8080" });
	chat = new chat_client(io_service, endpoint_iterator);
	t = new std::thread([this]() { io_service.run(); });
}


Game::~Game()
{
}

void Game::sendPassedCards(int a, int b, int c)
{
	std::string msg = "PASS " + std::to_string(a) + ' ' + std::to_string(b) + ' ' + std::to_string(c);
	sendMessage((char*)msg.data());
}

void Game::sendPlayedCard(int a)
{
	std::string msg = "PLAY " + std::to_string(a);
	sendMessage((char*)msg.data());
}

void Game::sendMessage(char* message)
{
	chat_message msg;
	msg.body_length(std::strlen(message));
	std::memcpy(msg.body(), message, msg.body_length());
	msg.encode_header();
	chat->write(msg);
}
