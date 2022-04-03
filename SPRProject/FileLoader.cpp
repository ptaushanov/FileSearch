#include "FileLoader.h"

bool FileLoader::loadSearchList() {
	vector<FileData>* loadedFileData = new vector<FileData>;
	fstream listFS;
	listFS.open(SEARCH_LIST_PATH, ios::in);

	if (!listFS.is_open())
	{
		cout << "--- Could not open search list! ---" << endl;
		cout << endl;
		return false;
	}

	string line;
	while (getline(listFS, line))
	{
		if (line.at(0) == '#') {
			continue;
		}

		vector<string> parts = IOHelper::splitString(line, '\t');
		FileData newFileData(stoi(parts.at(0)), parts.at(1), stoi(parts.at(2)));

		loadedFileData->push_back(newFileData);
	}

	DataStore::searchList = loadedFileData;
	listFS.close();
	return true;
};

bool FileLoader::saveSearchList() {
	if (DataStore::searchList == NULL) {
		return true;
	}

	fstream listFS;

	listFS.open(SEARCH_LIST_PATH, ios::out);

	if (!listFS.is_open())
	{
		cout << "--- Could not open search list! ---" << endl;
		cout << endl;
		return false;
	}

	for (FileData& fileData : *DataStore::searchList) {
		listFS << fileData;
	}

	listFS.close();
	return true;
}

bool FileLoader::saveSearchResult(vector<string>& searchResults) {
	fstream listFS;

	listFS.open(SEARCH_RESULT_PATH, ios::app);

	if (!listFS.is_open())
	{
		cout << "--- Could not open results list! ---" << endl;
		cout << endl;
		return false;
	}

	for (string line : searchResults) {
		listFS << line << endl;
	}

	listFS.close();
	return true;
}

size_t FileLoader::findFileSize(string path) {
	struct stat sb {};

	if (!stat(path.c_str(), &sb)) {
		return sb.st_size;
	}
	else {
		return 0;
	}
}