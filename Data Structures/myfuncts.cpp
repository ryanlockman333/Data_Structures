/*
Ryan Lockman
MyFuncts.cpp
Stand-alone function definitions.
*/

// Headers
#include <cctype> 
#include "myfuncts.h"

using namespace std;

string strToUpper(const std::string str) {
	std::string ans = str;

	// Process strToUpper
	for(size_t i = 0; i < str.length(); i++)
		ans[i] = toupper(str[i]);

	return ans;
}

string strToLower(const std::string str) {
	std::string ans = str;

	// Process strToLower
	for(size_t i = 0; i < str.length(); i++)
		ans[i] = tolower(str[i]);

	return ans;
}

char chrToUpper(const char chr) {
	char ans = toupper(chr);

	return ans;
}

char chrToLower(char chr) {
	char ans = tolower(chr);

	return ans;
}

int promptYN(const std::string reply) {
	int ans = 0;

	// Process Reply
	if	   (reply == "YES"		 || reply == "Yes"		 || reply == "yes"		 ||
		    reply == "SURE"		 || reply == "Sure"		 || reply == "sure"		 ||
		    reply == "OK"		 || reply == "Ok"		 || reply == "ok"		 ||
		    reply == "Y"		 || reply == "y")
		    ans = PLAY;
	else if(reply == "NO"        || reply == "No"		 || reply == "no"		 ||
		    reply == "QUIT"      || reply == "Quit"		 || reply == "quit"		 ||
			reply == "STOP"      || reply == "Stop"		 || reply == "stop"		 ||
			reply == "TERMINATE" || reply == "Terminate" || reply == "terminate" ||
			reply == "N"		 || reply == "n")
			ans = STOP;
	else
			ans = ERROR;

	return ans;
}

bool binarySearch(const char usedLetters[], const int used, const char letterToFind) {
	bool found      = false;
	int  midIndex   = 0;
	int  firstIndex = 0;
	int  lastIndex  = used - 1;

	// Process Binary Search
	while(!found && firstIndex <= lastIndex) {
		midIndex = (firstIndex + lastIndex) / 2;

		if(usedLetters[midIndex] == letterToFind)
	        found = true;
		else if(usedLetters[midIndex]  < letterToFind)
			firstIndex = midIndex + 1;
		else
			lastIndex  = midIndex - 1;
	}

	if(found)
		return true;
	else
		return false;
}

void bubbleSort(char usedLetters[], const int used) {
	char tmp;
	bool sorted = false;

	// Process Bubble Sort Ascending List
	while(!sorted) {
		sorted = true;
		for(int i = 0; i < used - 1; i++)
		{
			if(usedLetters[i] > usedLetters[i + 1])
			{
				tmp                = usedLetters[i];
				usedLetters[i]     = usedLetters[i + 1];
				usedLetters[i + 1] = tmp;
				sorted             = false;
			}
		}
	}
}

std::string mask(std::string str) {
     for(size_t i = 0; i < str.length(); i++)
		if(isprint(str[i]))
			str[i] = '_';
		else
			continue;
     
     return str;
}

std::string unmask(const char letter, const std::string str, std::string masked) {
     for(size_t i = 0; i < str.length(); i++) 
		if(str[i] == letter)
			masked[i] = letter;   
            
     return masked;
}

