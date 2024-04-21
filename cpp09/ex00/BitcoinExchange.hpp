#ifndef BITCOIN_HPP
#define BITCOIN_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdlib.h>

bool  exchangeLine(std::string line, std::map<std::string, float> dataMap);
bool error(std::string line);

#endif
