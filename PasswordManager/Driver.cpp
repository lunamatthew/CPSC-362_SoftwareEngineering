// Driver.cpp 
// Group 4 Software Engineering
// Password Manager driver

#include "FileHandlerLibrary.h"
#include "EncryptionLibrary.h"
#include <iostream>

bool exit_flag = false;

void displayMenu() {
	std::cout << "\n\nSmartLock Password Manager\n";
	std::cout << "1 - Store new Password\n";
	std::cout << "2 - Display stored Password\n";
	std::cout << "3 - Exit\n";
	std::cout << "\nPlease enter a valid input: ";
}

void enterNewPassword() {
	std::string password;
	std::cout << "\nPlease Input the password: ";
	std::cin >> password;

	password = encryptString(password);

	std::fstream file = openFile(FILE_NAME, WRITE);
	if (isFileNull(file)) {
		std::cout << "\nError Opening file... Password not stored.\n";
		return;
	} else 
		writeToFile(file, password);
	closeFile(file);
	std::cout << "\nPassword successfully saved!";
}

void displayPasswords() {
	std::string password;
	std::fstream file = openFile(FILE_NAME, READ);
	if (isFileNull(file)) {
		std::cout << "\nError Opening file... Password cannot be read.\n";
		return;
	} else {
		std::cout << "\nStored passwords are:";
		for (int i = 1; std::getline(file, password); ++i) {
			password = decryptString(password);
			std::cout << "\n\tPassword " << i << ": " << password;
		}
	}
	closeFile(file);
}

bool interpretInput(char input) {
	switch (input) {
		case '1':
			enterNewPassword();
			return false;
		case '2':
			displayPasswords();
			return false;
		case '3':
			//toggleExitFlag();
			return true;
		default:
			break;
	}
	return false; // repeat the menu without executing further instruction for non valid input.
}

void toggleExitFlag() {
	exit_flag = true;
}

int main() {
	char inputVal = ' ';
	bool isExitIssued = false;
	while (!isExitIssued) {
		displayMenu();
		std::cin >> inputVal;
		isExitIssued = interpretInput(inputVal);
	}
	std::cout << "\nSmartlock Password Manager Exiting...\n";
	return 0;
}
