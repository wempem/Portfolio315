#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include <string>
class Map{
    private:
	int mSize;
	std::vector<int> idArray;
	std::vector<std::string> strArray;
    public:
        Map();

        /* Adds (inserts) val with the associated key.
         * Returns if successful or not. (It is not successful if we are out
         * of memory, or if the key already exists.)
        */
        bool add(const char *key, int val);

        /* Search for they key. If found it sets ret to the correct val and 
         * returns true. Otherwise this function returns false.
         */
        bool get(const char *key, int &ret);

        /*returns the size (memory consumed) by this data structure.*/
        int size();

        /* Removes the current value from the Map AND frees up any memory 
         * that it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const char *key);

        /* Returns the number of names with a given prefix.
         * EX: If we have {John, Jonathan, Paul, Mark, Luke, Joanna} then
         * howMany("Jo") == 3.
         */
        int howMany(const char *prefix);

	int strLength(std::string str);
        void print();

        /*Frees all memory*/
        ~Map();
};

#endif
