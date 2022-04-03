#include "Menu.h"

void Menu::displayMenu()
{
	cout << string(65, '*') << endl;
	cout << '*' << string(63, ' ') << '*' << endl;
	cout << '*' << string(3, ' ') << string(20, '-') << " Search list " << string(20, '-') << "\t*" << endl;
	cout << '*' << string(63, ' ') << '*' << endl;
	cout << '*' << string(3, ' ') << "1) List all files in search list"
		<< "\t\t\t\t*" << endl;
	cout << '*' << string(3, ' ') << "2) Add new file to search list"
		<< "\t\t\t\t*" << endl;
	cout << '*' << string(63, ' ') << '*' << endl;
	cout << '*' << string(3, ' ') << string(19, '-') << " Search options " << string(19, '-') << "\t*" << endl;
	cout << '*' << string(63, ' ') << '*' << endl;
	cout << '*' << string(3, ' ') << "3) Search a word in file(s) by file ID"
		<< "\t\t\t*" << endl;
	cout << '*' << string(3, ' ') << "4) Search a word in the larges file in the search list"
		<< "\t*" << endl;
	cout << '*' << string(3, ' ') << "5) Search a word in the smallest file in the search list"
		<< "\t*" << endl;
	cout << '*' << string(63, ' ') << '*' << endl;
	cout << string(65, '*') << endl;
}

int Menu::takeMenuInput()
{
	int choice;

	IOHelper::getInteger(choice, "Choose from [1-9] or 0 for exit: ", "Input must be of type integer!");
	cout << endl;

	return choice;
}

void Menu::onViewSearchList() {
	IOHelper::clear();

	if (!DataStore::searchList) {
		cout << "------- No data in the search list -------" << endl;
		cout << endl;
		IOHelper::pause();
		return;
	}

	cout << "ID\tPATH\tSIZE" << endl;

	cout << endl;
	for (FileData& fileData : *DataStore::searchList) {
		cout << fileData;
	}
	cout << endl;

	IOHelper::pause();
}

void Menu::onAddToSearchList() {
	IOHelper::clear();

	string path;

	cout << "File path: ";
	cin.ignore();
	getline(cin, path);

	size_t size = FileLoader::findFileSize(path);

	if (size == 0) {
		cout << endl;
		cout << "------- Path is invalid or the file is empty! -------" << endl;
		cout << endl;
	}
	else {
		FileData newFileData(path, size);
		DataStore::addFileData(newFileData);
		cout << endl;
		cout << "(+) File was added successfuly to the search list" << endl << endl;
		cout << "ID\tPATH\tSIZE" << endl;
		cout << newFileData << endl;
	}

	IOHelper::pause();
}

void Menu::onWordSearch() {
	IOHelper::clear();

	string word, lineOfIds;

	cout << "Word to search for: ";
	cin >> word;

	cout << endl;

	cout << "ID of file(s): ";
	cin.ignore();
	getline(cin, lineOfIds);
	cout << endl;

	vector<string> _ids = IOHelper::splitString(lineOfIds, ' ');
	vector<string> paths;

	for (string _id : _ids) {
		try
		{
			int id = stoi(_id);
			FileData* foundFileData = DataStore::findFileDataByID(id);

			if (!foundFileData) {
				cout << "(-) Couldn't find file with id " << id;
				cout << " in the search list" << endl;
				continue;
			}

			paths.push_back(foundFileData->getPath());
		}
		catch (const invalid_argument&)
		{
			cout << "(-) Ignoring invalid argument " << _id << endl;
		}
	}

	vector<string> searchResults = FileSearch::searchFiles(paths, word);

	for (string line : searchResults) {
		cout << line << endl;
	}

	cout << endl;
	IOHelper::pause();
}

void Menu::onWordSearchWithSize(string size) {
	IOHelper::clear();

	string word;

	cout << "Word to search for: ";
	cin >> word;

	cout << endl;

	FileData* foundFileData = NULL;

	if (size == "Max") {
		foundFileData = DataStore::findFileDataWithSizeMax();
	}
	else if (size == "Min") {
		foundFileData = DataStore::findFileDataWithSizeMin();
	}
	else {
		cout << "(-) Wrong size for file search" << endl;
		cout << endl;
		IOHelper::pause();
	}

	if (!foundFileData) {
		cout << "(-) Failed to find file data with maximum size" << endl;
		cout << endl;
		IOHelper::pause();
	}

	string path = foundFileData->getPath();
	vector<string> searchResults = FileSearch::searchFile(path, word);

	for (string line : searchResults) {
		cout << line << endl;
	}

	cout << endl;
	IOHelper::pause();
}



void Menu::resolveChoice(int choice)
{
	switch (choice)
	{
	case 1:
		onViewSearchList();
		break;

	case 2:
		onAddToSearchList();
		break;

	case 3:
		onWordSearch();
		break;

	case 4:
		onWordSearchWithSize("Max");
		break;

	case 5:
		onWordSearchWithSize("Min");
		break;

	default:
		cout
			<< "Invalid choice! Please choose a value from [1-9] or 0 for exit." << endl
			<< endl;
		IOHelper::pause();
	}
}

void Menu::operateWithMenu() {

	// Main loop
	while (true)
	{
		IOHelper::clear();
		// Displaying menu
		displayMenu();

		cout << endl;

		// Taking parsed user input
		int choice = takeMenuInput();

		// On 0 => exit
		if (choice == 0)
		{
			return;
		}

		resolveChoice(choice);
	}
}