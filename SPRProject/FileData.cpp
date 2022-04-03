#include "FileData.h"

atomic<int> FileData::counter = 0;

FileData::FileData(string path, size_t  size) {
	this->id = counter;
	counter++;

	this->path = path;
	this->size = size;
}

FileData::FileData(int id, string path, size_t  size) {
	this->id = id;
	if (id >= counter) {
		counter = id + 1;
	}

	this->path = path;
	this->size = size;
}

int FileData::getId() {
	return id;
}

string FileData::getPath() {
	return path;
}

void FileData::setPath(string path) {
	this->path = path;
}

size_t FileData::getSize() {
	return size;
}

void FileData::setSize(size_t size) {
	this->size = size;
}

ostream& operator<<(ostream& os, FileData& fileData) {
	os << fileData.getId() << "\t";
	os << fileData.getPath() << "\t";
	os << fileData.getSize() << endl;
	return os;
}
