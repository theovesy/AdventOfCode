#include <iostream>
#include <fstream>
#include <string>

int score(int opponent, int player) {
	player -= 87;
	opponent -= 64;
	int score = player;
	if(player == opponent) {
		return score+3; // Equality
	} else if(player == opponent+1) {
		return score+6; // Win
	} else if(player == 1 && opponent == 3) {
		return score+6; // Win
	} else {
		return score; // Lose
	}
}

int score2(int opponent, int player) {
	player -= 87;
	opponent -= 64;
	if(player == 1) { // Lose
		int score = opponent-1;
		if(score == 0) return 3;
		return opponent-1;
	} else if (player == 2) { // Equal
		return opponent+3;
	} else { // Win
		int score = opponent+1;
		if(score == 4) return 7;
		return score+6;
	}
}

int main() {
	std::fstream input_file;
	input_file.open("input2", std::ios::in);
	if(input_file.is_open()) {
		std::string line;
		int total_score = 0;
		while(getline(input_file, line)) {
			char opponent = line[0];
			char player = line[2];
			total_score += score2((int)opponent, (int)player);
		}
		input_file.close();
		std::cout << "Final score : "<< total_score <<"\n";
	}
	return 0;
}

