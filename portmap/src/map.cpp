#include "map.hpp"
#include <iostream>
#include <vector>

Map::Map(){

}

/* Adds (inserts) val with the assoc
 * Returns if successful or not. (It
 * of memory, or if the key already
*/
bool Map::add(const char *key, int val){
//	std::cout << key;
	std::string str = key;
//	std::cout << str;
	if(val < 0){
		return false;
	}
	if(key == NULL || key == '\0'){
		return false;
	}
	for(std::vector<int>::iterator i = idArray.begin(); i != idArray.end(); i++){
		if(val == *i){
			std::cout << "ID already used";
			return false;
		}
	}	
	
	strArray.push_back(str);
	idArray.push_back(val);
	
	return true;

}
/* Search for they key. If found it
 * returns true. Otherwise this func
 */
bool Map::get(const char *key, int &ret){
	int index = -1;
	std::string str = key;
	for(std::vector<std::string>::iterator i = strArray.begin(); i != strArray.end(); i++){
		index++;
		if(str == *i){
			ret = idArray.at(index);
			return true;
		}
	}
	return false;
}

//returns the size (memory consumed)

int Map::size(){

}

/* Removes the current value from th
 * that it can.
 * Returns true if there was somethi
 */
bool Map::remove(const char *key){
	int index = -1;
	std::string str = key;
	for(std::vector<std::string>::iterator i = strArray.begin(); i != strArray.end(); i++){
		index++;
		if(str == *i){
			strArray.erase(i);
			idArray.erase(idArray.begin() + index);
			return true;
		}
	} 
	return false;
}

/* Returns the number of names with
 * EX: If we have {John, Jonathan, P
 * howMany("Jo") == 3.
 */
int Map::howMany(const char *prefix){
	std::string str = prefix;
	std::string temp;
	int length = strLength(str);
	int amount = 0;
	bool isTrue = false;
	for(std::vector<std::string>::iterator i = strArray.begin(); i != strArray.end(); i++){
		temp = *i;
		for(int j = 0; j < length; j++){
			if(temp[j] == str[j]){
				isTrue = true;	
			}
			else{
				isTrue = false;
				break;
			}
		}
		if(isTrue == true){
			amount++;
		}
		temp = "";
	}
	return amount;
}
int Map::strLength(std::string str){
	int index = 0;
	while(str[index] != '\0'){
		 index++;
	}
	return index;
}
void Map::print(){
	for(std::vector<std::string>::iterator i = strArray.begin(); i != strArray.end(); i++){
		std::cout << *i << " , ";
		//std::cout << idArray.at(i);
		//std::cout << "\n";
	}
	for(std::vector<int>::iterator i = idArray.begin(); i != idArray.end(); i++){
		std::cout << *i << " , ";
	}
}

/*Frees all memory*/
Map::~Map(){
	strArray.clear();
	idArray.clear();
}
