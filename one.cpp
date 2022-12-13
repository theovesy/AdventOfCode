#include <iostream>
#include <fstream>
#include <string>

int sum_table(int* tab, int len) {
    int sum = 0;
    for(int i=0;i<len;i++){
        sum += tab[i];
    }
    return sum;
}

void print_table(int* tab, int len) {
    for(int i=0;i<len;i++){
        std::cout << tab[i] << ", ";
    }
    std::cout << "\n";
}

int main() {
	int top3[] = {0,0,0};
	std::fstream input_file;
	input_file.open("inputs/input.txt", std::ios::in);
	if(input_file.is_open()) {
		std::string line;
		int sum = 0;
		while(getline(input_file, line)) {
			if(line == "") {
				for(int i=2;i>=0;i--) {
					if(sum > top3[i]){
						for(int j=0;j<i;j++){
							top3[j] = top3[j+1];
						}
						top3[i] = sum;
                        break;
					}
				}
				sum = 0;
			}
			else {
				sum += std::stoi(line);
			}
		}
		input_file.close();
		int max_calories = sum_table(top3, 3);
		std::cout << "Max calories : "<< max_calories << "\n";
	}
	return 0;
}
