#pragma once
using namespace std;
#include <iostream>
#include "IOHelper.h"
#include "FileData.h"
#include "DataStore.h"
#include "FileLoader.h"
#include "FileSearch.h"
#include <string>

static class Menu
{

private:
	// Visualizes the main manu in the console
	static void displayMenu();

	// Takes input from the user for the menu
	static int takeMenuInput();

	// Calls the correct method from the selected choice
	static void resolveChoice(int choice);

public:
	// Interaction with the menu
	static void operateWithMenu();

	static void onViewSearchList();
	static void onAddToSearchList();
	static void onWordSearch();
	static void onWordSearchWithSize(string size);
};