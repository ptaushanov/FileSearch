#pragma once
#include "FileData.h"
#include <vector>

class DataStore {
public:
	static vector<FileData>* searchList;
	static void addFileData(FileData& newFileData);
	static FileData* findFileDataByID(int id);
	static FileData* findFileDataWithSizeMax();
	static FileData* findFileDataWithSizeMin();
};