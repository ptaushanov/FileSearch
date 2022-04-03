#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <mutex>
#include "FileLoader.h"

using namespace std;

class FileSearch {
private:
	static mutex saveResultMutex;
public:
	static vector<string> searchFiles(vector<string> paths, string word);
	static vector<string> searchFile(string path, string word);
};