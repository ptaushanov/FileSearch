# CMakeList.txt : CMake project for SPRProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SPRProject "Program.cpp" "Program.h" "Menu.cpp"  "Menu.h" "IOHelper.cpp" "IOHelper.h" "FileLoader.cpp" "FileLoader.h" "FileData.cpp" "FileData.h" "DataStore.cpp" "DataStore.h" "FileSearch.cpp" "FileSearch.h")

# TODO: Add tests and install targets if needed.
