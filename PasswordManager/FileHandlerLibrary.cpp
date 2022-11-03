// FileHandlerLibrary.cpp
// Group 4 Software Engineering
// Function definitions for the File Handler Library.
// There is some unnecessary 'function wrappers' with a few of these functions, though at a later iteration it may become useful. We can always change/remove in later iteration.

#include "FileHandlerLibrary.h"

std::fstream openFile(std::string fileName, file_flag flag) {
	std::fstream file;
	switch (flag) {
		case READ:
			file.open(fileName, std::ios::in);
			break;
		case WRITE:
			file.open(fileName, std::ios::app);
			break;
		default:
			break;
	}
	return file;
}

void closeFile(std::fstream& fileStream) {
	fileStream.close();
}

bool isFileNull(std::fstream& file) {
	return file.fail();
}

void writeToFile(std::fstream& file, std::string str) {
	file << str;
	file << '\n'; // New line character added to deliminate each new password stored.
}
