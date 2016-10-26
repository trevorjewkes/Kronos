/*
* The Player Class holds information about each player in the game.
* The functions in this class will need to be written by the Player Networking group.
*
* -Ligia Frangello and Katie Sweet
*
*/
#include "Card.cpp"



class Player {
public:
	Player(std::string s) { ip = s; }
	void setHand(std::vector<Card> h) { hand = h; }
	std::vector<Card> getHand() {return hand;}
	std::string getip() { return ip; }
	int getroundScore() { return roundScore; }
	void setroundScore(int i) { roundScore = i; }
	void sortHand(){ std::sort(hand.begin(), hand.end());}//sorts player hand
	void setScore(int i) { Score = i; }
	int getScore() { return Score; }

private:
	int Score;
	std::vector<Card> hand;
	std::string ip;
	int roundScore; // Hearts
	std::vector<int> overallScore; // Everyone
	int bid; //Spades
	int bags; // Spades
	int tricksWon; // Spades

	
	std::vector<Card> requestCardsPassed(); //Hearts
	std::vector<Card> requestMove(); // Everyone
	int requestBid(); // Spades

	void updateGameStatus(/*coded message of state*/); //takes message from Game and adds hand to it
	void endTheRound(/*coded message of state*/); //returns true if ready for next round
	void endTheGame(/*coded message of state*/);
	

		
};