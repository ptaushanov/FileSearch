#include "FileSearch.h"

mutex FileSearch::saveResultMutex;

vector<string> FileSearch::searchFile(string path, string word) {
	vector<string> foundLines;

	fstream fs;
	fs.open(path, ios::in);

	if (!fs.is_open())
	{
		cout << "--- Could not open file! ---" << endl;
		cout << endl;
		return foundLines;
	}

	int lineNumber = 1;
	string line;
	while (getline(fs, line))
	{
		bool containsWord = IOHelper::containsString(line, word);
		if (containsWord) {
			string fileNameWithExtencion = path.substr(path.find_last_of("/\\") + 1);
			string outputLine = fileNameWithExtencion + "\t" + to_string(lineNumber) + "\t" + word;
			foundLines.push_back(outputLine);
		}

		lineNumber++;
	}

	fs.close();

	// Appending to file
	saveResultMutex.lock();
	FileLoader::saveSearchResult(foundLines);
	saveResultMutex.unlock();

	return foundLines;
}


vector<string> FileSearch::searchFiles(vector<string> paths, string word) {
	vector<shared_future<vector<string>>> futureValues;
	vector<string> foundLines;

	// Running search in all files in parallel
	for (string path : paths) {
		shared_future<vector<string>> foundInFileFuture = async(launch::async, searchFile, path, word);
		futureValues.push_back(foundInFileFuture);
	}

	// Assembling the results
	for (auto& futureValue : futureValues) {
		vector<string> foundInFile = futureValue.get();
		foundLines.insert(foundLines.end(), foundInFile.begin(), foundInFile.end());
	}

	return foundLines;
}
