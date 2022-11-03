// FileHandlerLibrary.h
// Group 4 Software Engineering
// Supplimentary Header (Prototyping)

#ifndef FILEHANDLERLIBRARY_H
#define FILEHANDLERLIBRARY_H

#include <fstream>

enum file_flag { READ, WRITE };
const std::string FILE_NAME = "ENCRYPTED_DATA.txt";

std::fstream openFile(std::string fileName, file_flag flag);
void closeFile(std::fstream& fileStream);
bool isFileNull(std::fstream& file); // Checks if file stream is currently returning nullptr i.e. error with file stream.
void writeToFile(std::fstream& file, std::string str);

#endif
