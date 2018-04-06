#include "map.hpp"
#include <iostream>
int main(int argc, char *argv[]){
	int ret = 0;
	// creates map
	Map *map = new Map();
	// outputs if add works
	std::cout << map->add("Matt W", 2);
	std::cout << map->add("Matthew J", 3);	

//	std::cout <<map->add("Jackson Josh", 5);
//	std::cout << map->remove("Matthew J");

	// adds two more students
	map->add("Jones Tim", 10);
	map->add("Zach Smith", 12);
//	std:: cout << map->get("Matthew J", ret);
//	std::cout << "ret is: " << ret << "\n";

	//new line for formatting
	std::cout << "\n";
	//outputting how many students with begining value of MA
	std::cout << map->howMany("Ma");
//	std:: cout << "\n";
//	map->print();
//	delete map;
	return 0;
}
