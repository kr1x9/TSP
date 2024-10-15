#include <iostream>
#include <string>

//using namespace std;
// std::cin std::cout std::endl std::string


enum objectType {ROCK, PAPER, SCISSORS};


void mainMenu(bool& keepGoing);
void getUserInput(objectType& play1, objectType& play2);
objectType returnRPS(char inChar);
std::string calculateWinner(objectType play1, objectType play2);
void tallyWinsAndDisplayResults(objectType play1, objectType play2, int& wins1, int& wins2, int& ties);
void rpsSelection(char rPS);

int main() {
	bool keepGoing = true;
	int count = 0;
	int p1_wins = 0;
	int p2_wins = 0;
	int ties = 0;
	objectType player1, player2;
	
	do {
		
		mainMenu(keepGoing);
		if (!keepGoing)
			continue;
		getUserInput(player1, player2);
		tallyWinsAndDisplayResults(player1, player2, p1_wins, p2_wins, ties);
		count++;
		


	} while (keepGoing);
	
	std::cout << "Games played: " << count << std::endl;
	std::cout << "Player 1 wins: " << p1_wins << std::endl;
	std::cout << "Player 2 wins: " << p2_wins << std::endl;
	std::cout << "Ties: " << ties << std::endl;
	std::cout << std::endl;
	
	return 0;
}

void getUserInput(objectType& play1, objectType& play2) {
	char p1, p2;
	std::string
 selection;
	std::cout << "Player 1 select (R)ock (P)aper or (S)cissors: r/p/s ";
	std::cin >> p1;
	std::cout << "Player 1 selects ";
	rpsSelection(p1);
	std::cout << std::endl << std::endl;
	
	
	
	std::cout << "Player 2 select (R)ock (P)aper or (S)cissors: r/p/s ";
	std::cin >> p2;
	std::cout << "Player 2 selects ";
	rpsSelection(p2);
	std::cout << std::endl << std::endl;
	
	play1 = returnRPS(p1);
	play2 = returnRPS(p2);
	
	
	
	
}
void tallyWinsAndDisplayResults(objectType play1, objectType play2, int& wins1, int& wins2, int& ties) {
	std::string winner = calculateWinner(play1, play2);
	if (winner == "Player 1")
		wins1++;
	else if (winner == "Player 2")
		wins2++;
	else
		ties++;
	
	std::cout << "The winner is: " << winner << std::endl << std::endl;
}
std::string calculateWinner(objectType play1, objectType play2) {
	
	if ((play1 == ROCK && play2 == SCISSORS) || (play1 == SCISSORS && play2 == PAPER) || (play1 == PAPER && play2 == ROCK)) {
		return "Player 1";
		
	} else if (play1 == play2) {
		return "TIE!";
	} else { 
		return "Player 2";
	}
}
void rpsSelection(char rPS) {
	int b = static_cast<int>(rPS);
	switch (b) {
		case 'r': case 'R':
			std::cout << "ROCK";
			break;
		case 'p': case 'P':
			std::cout << "PAPER";
			break;
		case 's': case 'S':
			std::cout << "SCISSORS";
			break;
	}
}

objectType returnRPS(char inChar) {
	
	switch (inChar) {
		case 'r': 
		case 'R':
			return ROCK;
		case 'p': 
		case 'P':
			return PAPER;
		case 's':
		case 'S':
			return SCISSORS;
			
	}
	
}
