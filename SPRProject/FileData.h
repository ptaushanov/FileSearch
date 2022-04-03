#pragma once
#include <atomic>
#include <string>
#include <iostream>
#include <filesystem>

using namespace std;

class FileData {
private:
	static atomic<int> counter;
	int id;
	string path;
	size_t size;

public:
	FileData(string path, size_t size);
	FileData(int id, string path, size_t size);
	int getId();
	string getPath();
	void setPath(string path);
	size_t getSize();
	void setSize(size_t size);

	friend ostream& operator<<(ostream& os, FileData& fileData);
};