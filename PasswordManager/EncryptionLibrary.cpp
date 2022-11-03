// EncripytionLibrary.cpp
// Group 4 Software Engineering
// Function definitions for the EncryptionLibrary
// This makes use of an extremely basic cipher. We can make this more complex through the iterations.

#include "EncryptionLibrary.h"

std::string encryptString(std::string str) {
	int tmpStrSize = str.size(); 
	for (int i = 0; i < tmpStrSize; ++i) {
		if (i % 2 == 0)
			str[i] += 10;
		else 
			str[i] -= 10;
	}
	return str;
}

std::string decryptString(std::string str) {
	int tmpStrSize = str.size();
	for (int i = 0; i < tmpStrSize; ++i) {
		if (i % 2 == 0)
			str[i] -= 10;
		else
			str[i] += 10;
	}
	return str;
}
