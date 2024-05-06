#include "BitcoinExchange.hpp"

bool checkValue(std::string value)
{
    std::istringstream iss(value);
    long double f;
    std::string str;
    if (!(iss >> f) || iss >> str)
        return (error("not a numeric value"));
    if (f > 2147483647)
        return (error("too large number."));
    if (f < 0)
        return (error("not a positive number."));
    return (true);
}

bool parseDate(std::string date)
{
    std::istringstream iss(date);
    int year, month, day;

    char dash;
    iss >> year >> dash >> month >> dash >> day;
    if (month > 12 || month < 1 || day > 31 || day < 1)
        return (false);
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return (false);
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
                return (false);
        }
        else
            if (day > 28)
                return (false);
    }
    return (true);
}

void printLine(std::string line, std::map<std::string, float> dataMap)
{
    std::string date = line.substr(0, 10);
    const char *number = line.c_str();
    number += 13;
    float value = atof(number);
    std::map<std::string, float>::const_iterator next;
    next = dataMap.upper_bound(date);
    while (next->first > date)
        next--;
    std::cout << date << " => "<< value << " = " << value * next->second << std::endl;
}

bool checkInputFormat(std::string str) {
    std::istringstream iss(str);
    int year, month, day;
    char dash1, dash2, pipe;
    if (!(iss >> year >> dash1 >> month >> dash2 >> day >> pipe))
        return (false);
    if (iss.fail() || dash1 != '-' || dash2 != '-' || pipe != '|')
        return (false);
    if (str[4] != '-' || str[7] != '-' || str[10] != ' ' || str[12] != ' ')
        return (false);
    return (true);
}
bool exchangeLine(std::string line, std::map<std::string, float> dataMap)
{
    (void)dataMap;
    if (!checkInputFormat(line))
        return (error("bad input => " + line));
    if (!parseDate(line.substr(0, 10)))
        return (error("incorrect date."));
    if (checkValue(line.substr(13)))
        printLine(line, dataMap);
    return (true);
}
