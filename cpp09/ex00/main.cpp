#include "BitcoinExchange.hpp"

bool error(std::string line)
{
    std::cerr << "Error: " << line << std::endl;
    return (false);
}

std::map<std::string, float> openDataFile()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
         throw std::invalid_argument("Impossible d'ouvrir le fichier de la data.");
    std::map<std::string, float> dataMap;
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key;
        float value;
        std::getline(ss, key, ',');
        ss >> value;
        dataMap[key] = value;
    }
    return (dataMap);
}

int main(int argc, char **argv)
{

    try {
        if (argc != 2)
            return (error("format: ./btc inputFile"));
        std::map<std::string, float> dataMap = openDataFile();
        std::ifstream file(argv[1]);
        if (!file.is_open())
            return (error("can't open input file."));
        std::string line;
        while (std::getline(file, line))
            exchangeLine(line, dataMap);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
