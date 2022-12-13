#include <iostream>
#include <fstream>
#include <string>

char find_common_char(std::string str) {
	int len = str.length();
	for(int i=0;i<len/2;i++) {
		for(int j=len/2;j<len;j++) {
			if(str[j] == str[i]) return str[j];
		}
	}
	return 0;
}

int priority(std::string pack){
	int common = (int)find_common_char(pack);
	if(common > 96){
		return common-96;
	} else {
		return common-64+26;
	}
}

int main() {
	std::fstream input_file;
	input_file.open("input3", std::ios::in);
	if(input_file.is_open()) {
		std::string line;
		int total_score = 0;
		while(getline(input_file, line)) {
			total_score += priority(line);
		}
		input_file.close();
		std::cout << "Total : "<< total_score <<"\n";
	}
	return 0;
}

