#pragma once
#include <vector>
#include "FileData.h"
#include "FileLoader.h"
#include "DataStore.h"
#include "IOHelper.h"
#include <fstream>
#include <cstring> 
#include <string>
#include <iostream>
#define SEARCH_LIST_PATH "list.txt"
#define SEARCH_RESULT_PATH "result.txt"

using namespace std;

class FileLoader {
public:
	static bool loadSearchList();
	static bool saveSearchList();
	static bool saveSearchResult(vector<string>& searchResults);
	static size_t findFileSize(string path);
};
