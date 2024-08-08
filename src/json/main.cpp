#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
// #include "json.h"
using std::cout, std::cin, std::endl;

void retrieve_pair(const std::string& string, std::string::iterator& it) {
	std::string key, value;
	while(*it != '"')
		key += *it++;
	
	++it;
	
	while(*it != ':') 
		++it;
	++it;
	
	while(*it == ' ')
		++it;
	
	while(*it != ',' && *it != '}') // продолдить отсюда!!!!!!!!!!!!!!!!!!!!!!!!!
		value += *it++;
	++it;
	
	
	cout << endl << endl << key << "---" << value;
}


void read_object(const std::string& string, std::string::iterator& it) {
	bool key = true;
	bool value = false;
	bool start = false; // Флаг начала записывания ключа/значения в переменную
	
	bool slash = false; // Для экранирования ПОТОМ
	
	std::string skey, svalue;
	
	
	while(*it != '}') {
		if(*it == '"') retrieve_pair(string, ++it);
		else ++it;	
	}
	
}


int main() {
    std::ifstream stream("file.json");
    if(!stream) {
    	std::cerr << "Impossible to open the file" << std::endl;
    	return 1;
    }
    
    
    std::string line, string;
    while(std::getline(stream, line))
    	string += line;
    cout << string;
    
    
    std::string::iterator it = string.begin();
    while(it != string.end()) {
    	if(*it == '{')
    		read_object(string, ++it);
    	return 2;
   
    }
     
    
    stream.close();
    return 0;
}

