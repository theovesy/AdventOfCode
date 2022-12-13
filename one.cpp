#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int top3[] = {0,0,0};
	std::fstream input_file;
	input_file.open("input", ios::in);
	if(input_file.is_open()) {
		std::string line;
		int sum = 0;
		while(getline(input_file, line)) {
			if(line == "") {
				for(int i=2;i<0;i--) {
					if(sum > top3[i]){
						for(int j=0;j<i;j++){
							top3[j] = top3[j+1];
						}
						top3[i] = sum;
					}
				}
				sum = 0;
			}
			else {
				sum += std::stoi(line);
			}
		}
		input_file.close();
		int max_calories = 0;
		for(int i=0;i<3;i++){
			max_calories+=top3[i];
		}
		std::cout << "Max calories : "<< max_calories << "\n";
	}
	return 0;
}

