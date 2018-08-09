/*
Ryan Lockman
MyFuncts.h
Stand alone function declarations.
*/

#ifndef MYFUNCTS_H
#define MYFUNCTS_H

// Headers
#include <string>

// Defined Constants
#define PLAY   1
#define STOP   0
#define ERROR -1

// Function Prototypes
std::string strToUpper(const std::string str);
std::string strToLower(const std::string str);
char chrToUpper(const char chr);
char chrToLower(const char chr);
int promptYN(const std::string reply);
bool binarySearch(const char usedLetters[], const int used, const char letterToFind);
void bubbleSort(char usedLetters[], const int used);
std::string mask(std::string str);
std::string unmask(const char letter, const std::string str, std::string masked);

#endif

