#ifndef FILEIO_H
#define FILEIO_H

#include<string>
#include<map>

template <typename T>
void saveToFile(std::map<std::string, T> data, std::string filename);

template <typename T>
std::map<std::string, T> loadFromFile(std::string filename);

#endif