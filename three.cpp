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

char find_common_char_3str(std::string str1,
		std::string str2, std::string str3) {
	for(int i=0;i<str1.length();i++) {
		for(int j=0;j<str2.length();j++) {
			for(int k=0;k<str3.length();k++) {
				if(str1[i] == str2[j] && str2[j] == str3[k]) return str1[i];
			}
		}
	}
	return 0;
}

int char_priority(char character) {
	int common = (int)character;
	if(common > 96){
		return common-96;
	} else {
		return common-64+26;
	}
}

int priority(std::string str1,
		std::string str2, std::string str3){
	char common = find_common_char_3str(str1, str2, str3);
	return char_priority(common);
}

int main() {
	std::fstream input_file;
	input_file.open("inputs/input3.txt", std::ios::in);
	if(input_file.is_open()) {
		std::string line;
		int total_score = 0;
		int count = 0;
		std::string str[3];
		while(getline(input_file, line)) {
			if(count == 3) {
				total_score += priority(str[0], str[1], str[2]);
				count = 0;
			}
			str[count] = line;
			count++;
		}
		input_file.close();
		std::cout << "Total : "<< total_score <<"\n";
	}
	return 0;
}

