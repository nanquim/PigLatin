#include <iostream>
#include <string>
#include <algorithm>

/*RULES: 
1. If a word starts with a consonant and a vowel, put the first letter of the word at the end of the word and add "ay."
2. If a word starts with two consonants move the two consonants to the end of the word and add "ay."
3. If a word starts with a vowel add the word "way" at the end of the word. */

bool isConsonant(std::string str, char pos);
bool isVowel(std::string str, char pos);
void formatOutput(std::string& str);

int main(){

	std::string str;

	std::cout << "\nEnter any WORD: " << std::endl;
	getline(std::cin, str);
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);

	if(str.empty()){
		std::cerr << "ERROR - Empty String" << std::endl;
	}else if(isConsonant(str, str.at(0)) == true){
		if(isConsonant(str, str.at(1)) == true){
			str += str.at(0);
			str += "ay";
			str.erase(0, 1);
			formatOutput(str);
			std::cout << "\nString Translation to Pig Latin: " << str << std::endl;
		}else if(isVowel(str, str.at(1)) == true){
			str += str.at(0);
			str += str.at(1);
			str += "ay";
			str.erase(0, 1);
			formatOutput(str);
			std::cout << "\nString Translation to Pig Latin: " << str << std::endl;
		}
	}else if(isVowel(str, str.at(0)) == true){
		str += "way";
		formatOutput(str);
		std::cout << "\nString Translation to Pig Latin: " << str << std::endl;
	}
}

bool isConsonant(std::string str, char pos){
	std::string consonants = "BCDFGHJKLMNPQRSTVWXYZ";
	for(int i=0; i<consonants.length(); ++i){ 
		if(str.at(0) == consonants[i]){
			return true; 
		}
	}
	return false;
}

bool isVowel(std::string str, char pos){
	std::string vowels = "AEIOU";
	for(int i=0; i<vowels.length(); ++i){
		if(str.at(0) == vowels[i]){
			return true; 
		}
	}
	return false;
}

void formatOutput(std::string& str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	str[0] = toupper(str[0]);
}

//Criado por Juliana (nanquim) em 17/06/2016
