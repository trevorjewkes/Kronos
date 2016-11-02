//
// chat_server.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include "chat_message.hpp"
#include "HeartsGame.hpp"

int totalId = 0;
int roundId = 0;
int turns = 0;
int checker = 0;
HeartsGame game;
std::vector<Player> players;
int currentPlayer = 0;

using boost::asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant
{
public:
  virtual ~chat_participant() {}
  virtual void deliver(const chat_message& msg) = 0;
  int id;
};

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room
{
public:
  void join(chat_participant_ptr participant, std::string ip)
  {
	  participant->id = totalId++;
	  std::cout << totalId << std::endl;
    participants_.insert(participant);
	game.addPlayer(totalId, ip);
	if (totalId == 4)
	{
		players = game.play_Hearts();
		std::cout << "Got to here." << std::endl;
		for (auto participant1 : participants_)
		{
			sendCards(participant1);
			sendRequest(participant1, "PASS");
		}
	}
   /* for (auto msg: recent_msgs_)
      participant->deliver(msg);*/
	/*chat_message msg;
	char* message = "Choose 3 cards to pass";
	msg.body_length(std::strlen(message));
	std::memcpy(msg.body(), message, msg.body_length());
	msg.encode_header();
	participant->deliver(msg);*/
	//Change this. it is the HandleNewConnection function
  }

  void sendRequest(chat_participant_ptr participant, char* message)
  {
	  std::string Msg = "REQUEST " + std::string(message);
	  chat_message msg;
	  msg.body_length(Msg.size());
	  std::memcpy(msg.body(), Msg.data(), msg.body_length());
	  msg.encode_header();
	  participant->deliver(msg);
  }

  void sendCards(chat_participant_ptr participant)
  {
	  std::string message = "CARDS ";
	  message += std::to_string(game.players[participant->id].getHand().size());
	  for (int i = 0; i < game.players[participant->id].getHand().size(); i++)
	  {
		  message += ' ' + std::to_string(game.players[participant->id].getHand()[i].getSuit());
		  message += ' ' + std::to_string(game.players[participant->id].getHand()[i].getValue());
	  }
	  chat_message msg;
	  msg.body_length(message.size());
	  std::memcpy(msg.body(), message.data(), msg.body_length());
	  msg.encode_header();
	  participant->deliver(msg);
  }

  void leave(chat_participant_ptr participant)
  {
	  for (auto participant_i : participants_)
		  if (participant_i->id > participant->id) participant_i->id--;
	  totalId--;
	  std::cout << "Player " << participant->id + 1 << " just left." << std::endl;
    participants_.erase(participant);
  }

  void deliver(const chat_message& msg, std::string ip)
  {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
      recent_msgs_.pop_front();

	//for (auto participant : participants_)
	//{
	std::string message = "";
	for (int i = 0; i < msg.body_length(); i++)
		message += msg.body()[i];// participant->deliver(msg);
	std::cout << message;
	if (message[0] == '1')
	{
		for (auto participant : participants_)
		{
			char* message = "Here are your cards.";
			chat_message tmpMsg;
			tmpMsg.body_length(std::strlen(message));
			std::memcpy(tmpMsg.body(), message, tmpMsg.body_length());
			tmpMsg.encode_header();
			participant->deliver(tmpMsg);
		}
	}
	if (message.size() > 4)
	{
		
		std::string request = "";
		for (int i = 0; i < 4; i++)
		{
			request += message[i];
		}
		std::string values = "";
		for (int i = 5; i < message.size(); i++)
		{
			values += message[i];
		}	
		if (request == "PASS")
		{
			if (parsePass(values, ip) == 4)
			{
				game.passCards(roundId++);
				checker = 0;
				for (auto participant1 : participants_)
				{
					sendCards(participant1);
					sendUpdate(participant1);
					if (participant1->id == (game.findTwoOfClubs()))
					{
						sendRequest(participant1, "PLAY");
						currentPlayer = participant1->id;
					}
				}							
			}
		}
		if (request == "PLAY")
		{
			int tmpId = game.playCard(values, ip, checker++, currentPlayer);
			if (tmpId == -1)
			{
				for (auto participant1 : participants_)
				{
					if (participant1->id == currentPlayer)
					{
						sendRequest(participant1, "PLAY");
					}
				}
			}
			else
			{
				currentPlayer++;
				turns++;
				if (currentPlayer > 3) currentPlayer = 0;
				for (auto participant1 : participants_)
				{
					if (participant1->id == tmpId)
						sendCards(participant1);
					sendUpdate(participant1);
					if (participant1->id == currentPlayer && turns < 4)
						sendRequest(participant1, "PLAY");
					else if(turns >= 4)
					{
						turns = 0;
						//calcscore
						sendUpdate(participant1);
						//send to first player again
					}
				}
			}
		}
	}
	//}
	std::cout << std::endl;
  }

  void sendUpdate(chat_participant_ptr participant)
  {
	  std::string message = "UPDATE CENTER ";
	  message += std::to_string(game.centerPile.size());
	  message += ' ';
	  for (int i = 0; i < game.centerPile.size(); i++)
	  {
		  message += ' ' + std::to_string(game.centerPile[i].getSuit());
		  message += ' ' + std::to_string(game.centerPile[i].getValue());
	  }
	  message += " SCORES";
	  for (int i = 0; i < game.players.size(); i++)
	  {
		  message += ' ' + std::to_string(game.players[i].getTotalScore());
	  }
	  chat_message msg;
	  msg.body_length(message.size());
	  std::memcpy(msg.body(), message.data(), msg.body_length());
	  msg.encode_header();
	  participant->deliver(msg);
  }

  int parsePass(std::string request, std::string ip)
  {
	  std::vector<int> cards;
	  std::string tmp = "";
	  for (int i = 0; i < request.size(); i++)
	  {
		  if (request[i] != ' ')
			  tmp += request[i];
		  else
		  {
			  cards.push_back(atoi(tmp.data()));
			  tmp.clear();
		  }
	  }
	  cards.push_back(atoi(tmp.data()));
	  game.setPassCards(cards, ip, checker++);
	  passes++;
	  return passes;
  }

private:
  std::set<chat_participant_ptr> participants_;
  enum { max_recent_msgs = 100 };
  chat_message_queue recent_msgs_;
  int passes = 0;
};

//----------------------------------------------------------------------

class chat_session
  : public chat_participant,
    public std::enable_shared_from_this<chat_session>
{
public:
  chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
      room_(room)
  {
  }

  void start(std::string ip)
  {
    room_.join(shared_from_this(),ip);
    do_read_header();
  }

  void deliver(const chat_message& msg)
  {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
      do_write();
    }
  }

private:
  void do_read_header()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.data(), chat_message::header_length),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec && read_msg_.decode_header())
          {
            do_read_body();
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  void do_read_body()
  {
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            room_.deliver(read_msg_, socket_.remote_endpoint().address().to_string());
            do_read_header();
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  void do_write()
  {
    auto self(shared_from_this());
    boost::asio::async_write(socket_,
        boost::asio::buffer(write_msgs_.front().data(),
          write_msgs_.front().length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
              do_write();
            }
          }
          else
          {
            room_.leave(shared_from_this());
          }
        });
  }

  tcp::socket socket_;
  chat_room& room_;
  chat_message read_msg_;
  chat_message_queue write_msgs_;
};

//----------------------------------------------------------------------

class chat_server
{
public:
  chat_server(boost::asio::io_service& io_service,
      const tcp::endpoint& endpoint)
    : acceptor_(io_service, endpoint),
      socket_(io_service)
  {
    do_accept();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(socket_,
        [this](boost::system::error_code ec)
        {
          if (!ec)
          {
            std::make_shared<chat_session>(std::move(socket_), room_)->start(socket_.remote_endpoint().address().to_string());
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  tcp::socket socket_;
  chat_room room_;
};

//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  try
  {
    /*if (argc < 2)
    {
      std::cerr << "Usage: chat_server <port> [<port> ...]\n";
      return 1;
    }*/

    boost::asio::io_service io_service;

    std::list<chat_server> servers;
    //for (int i = 1; i < argc; ++i)
    {
      tcp::endpoint endpoint(tcp::v4(), 8080);
      servers.emplace_back(io_service, endpoint);
    }

    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}