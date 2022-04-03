#include "IOHelper.h"

void IOHelper::getInteger(int& input, string inputMessage, string errorMessage)
{
	cout << inputMessage;

	while (!(cin >> input))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << errorMessage << endl
			<< endl;
		cout << inputMessage;
	}
}

void IOHelper::clear()
{
#if defined _WIN32
	system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined(__APPLE__)
	system("clear");
#endif
}

void IOHelper::pause()
{
	cout << "Press any key to continue ... ";
	cin.ignore();
	cin.get();
}


// Splits a string input value into a vector based on a given delimiter
vector<string> IOHelper::splitString(string _string, char _delimiter)
{
	vector<string> result;
	string current = "";

	for (int i = 0; i < _string.length(); i++)
	{
		char currChar = _string[i];
		if (currChar == _delimiter)
		{
			result.push_back(current);
			current = "";
		}
		else
		{
			current += currChar;
		}
	}

	if (current.length() > 0)
	{
		result.push_back(current);
	}

	return result;
}

bool IOHelper::containsString(string source, string target) {
	if (source.find(target) != string::npos) {
		return true;
	}
	return false;
}
