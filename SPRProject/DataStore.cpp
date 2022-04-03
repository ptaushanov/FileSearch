#include "DataStore.h"

vector<FileData>* DataStore::searchList = NULL;

void DataStore::addFileData(FileData& newFileData) {
	if (!searchList) {
		searchList = new vector<FileData>;
	}

	searchList->push_back(newFileData);
}

FileData* DataStore::findFileDataByID(int id) {
	for (FileData& fileData : *searchList) {
		if (fileData.getId() == id) {
			return &fileData;
		}
	}
	return NULL;
}

FileData* DataStore::findFileDataWithSizeMax() {
	FileData* maxSizeFileData = NULL;

	for (FileData& fileData : *searchList) {
		if (maxSizeFileData == NULL) {
			maxSizeFileData = &fileData;
		}
		else if (maxSizeFileData->getSize() < fileData.getSize()) {
			maxSizeFileData = &fileData;
		}
	}

	return maxSizeFileData;
}

FileData* DataStore::findFileDataWithSizeMin() {
	FileData* minSizeFileData = NULL;

	for (FileData& fileData : *searchList) {
		if (minSizeFileData == NULL) {
			minSizeFileData = &fileData;
		}
		else if (minSizeFileData->getSize() > fileData.getSize()) {
			minSizeFileData = &fileData;
		}
	}

	return minSizeFileData;
}
