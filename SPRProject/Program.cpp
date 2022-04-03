#include "Program.h"

int onError() {
	IOHelper::pause();
	return 1;
}

int main()
{
	bool loadedSearchList = FileLoader::loadSearchList();

	if (!loadedSearchList) {
		IOHelper::pause();
	}

	Menu::operateWithMenu();

	bool savedSearchList = FileLoader::saveSearchList();

	if (!savedSearchList) {
		return onError();
	}

	IOHelper::pause();
	return 0;
}
