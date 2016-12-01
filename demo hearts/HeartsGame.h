#include "Player.h"
#include "chatClient.cpp"
#include <boost/asio.hpp>



class HeartsGame
{
public:
	HeartsGame();
	~HeartsGame();
	void play_Hearts(int num);
	

private:
	boost::asio::ip::tcp::resolver *m_resolver;
	boost::asio::io_service io_service;
	std::thread *t;
	
	chat_client *chat;

	std::string suite(int i);  //converts enum ints to string of suit
	std::vector<Card> initializeDeck();
	std::string makename(int n);  //converts Player + int into Player names
	std::vector<Player> creatPlayers(int p);  //Creats a vector of Players to play the game.
	std::string value(int i);
	void displayCards(std::vector<Card>& hand);//displays the deck for screen purposes.
	void dealCards(std::vector<Player>& players, std::vector<Card>& Deck);
	int findTwoOfClubs(std::vector<Player>& p);  //looks through each hand to find the 2 of clubs
	Card getCardsToPass(std::vector<Card>& h, std::string p);  //gets and stores cards for passing
	int fixPass(int r, int p, int c);
	void assignPassedCards(std::vector<Player>& p, std::vector<Card>& h, int r);  //takes the passed cards and redistributes based on round
	int passCards(std::vector<Player>& p, int round);  //function for passing cards at beginging of round
	int scoretrick(std::vector<Card>& center, std::vector<Player>& players, int& turn);
	void displayroundScores(std::vector<Player> p);
	void displayScores(std::vector<Player> p);
	bool allhearts(std::vector<Card> h);  //checks to see if a players hand is all hearts.
	bool noLeadSuit(Suit s, std::vector<Card> h);  //compares hand against the lead suit
	bool validateMove(Player& p, bool& broken, std::vector<Card> Center, Card move, int t, int i);
	Card getmove(Player& p, bool& b, std::vector<Card> c, int t, int i);
	void updateScore(std::vector<Player>& p); //adds round score to Score
	bool playRound(std::vector<Player>& players, std::vector<std::vector<Card>>& history, int round);
	void startGame(std::vector<Player>& players, std::vector<std::vector<Card>>& history);  //uses players and calls round until game is over
	void sendMessage(char* message);
};

