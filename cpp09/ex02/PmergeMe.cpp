#include "PmergeMe.hpp"

bool isInteger(char **tokens, int ac)
{
	std::string token;
	for (int j = 1; j < ac; ++j)
	{
		token = tokens[j];
		for (size_t i = 0; i < token.length(); ++i) {
			if (!isdigit(token[i])) {
				return false;
			}
		}
	}
	return true;
}

