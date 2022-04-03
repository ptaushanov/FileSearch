#pragma once
#include <iostream>
#include <vector>
using namespace std;

class IOHelper {
public:
	// Gets integer input from console and validates it
	static void getInteger(int& input, string inputMessage, string errorMessage);
	// Clears console
	static void clear();
	// Pauses program and waits for input
	static void pause();
	// Splits the input string by a defined delimiter
	static vector<string> splitString(string _string, char _delimiter);
	// Finds if a strings is contained in another string
	static bool containsString(string source, string target);
};