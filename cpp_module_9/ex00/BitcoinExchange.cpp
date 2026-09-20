#include "BitcoinExchange.hpp"

BtcExchange::BtcExchange(): sheet()
{
    std::cout << "Default constructor is done!" << std::endl;
}

BtcExchange::BtcExchange(const BtcExchange& cpy): sheet(cpy.sheet)
{
    std::cout << "the copy constructor is done!" << std::endl;
}

BtcExchange& BtcExchange::operator=(const BtcExchange& op)
{
    if(this != &op)
    {
        this->sheet = op.sheet;
    }
    std::cout << "the assignement  constructor is done!" << std::endl;
    return *this;
}

BtcExchange::~BtcExchange(){}

bool BtcExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && isLeapYear)
        daysInMonth[2] = 29;

    if (day < 1 || day > daysInMonth[month])
        return false;

    return true;
}

bool BtcExchange::isValidValue(const std::string &valueStr, float &value) const
{
    char *endptr;
    double val = std::strtod(valueStr.c_str(), &endptr);

    if (endptr == valueStr.c_str() || *endptr != '\0')
    {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (val < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }

    value = static_cast<float>(val);
    return true;
}

bool BtcExchange::loadDatabase(const std::string &filename)
{
    std::string line;
    std::ifstream file(filename.c_str());
    if(!file)
    {
        std::cerr << "Error! Could not open File" << std::endl;
        return false;
    }
    if(!std::getline(file,line))
    {
        std::cerr << "Error!the file is empty!" << std::endl;
        return false;
    }
    std::string date;
    std::string value;
    while (std::getline(file,line))
    {
        std::stringstream ss(line);
        if(std::getline(ss,date,',') && std::getline(ss,value))
        {
            float rate = std::atof(value.c_str());
            sheet[date] = rate;
        }
    }
    if(sheet.empty())
    {
        std::cerr << "Error: database contains no valid data entries." << std::endl;
        return false;
    }
        
    return true;
}

void BtcExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error! Could not open File" << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(file, line))
    {
        std::cerr << "Error!the file is empty!" << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, pipe, value;

        if (!(ss >> date >> pipe >> value) || pipe != "|")
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float val;
        if (!isValidValue(value, val))
        {
            continue;
        }

        std::map<std::string, float>::const_iterator it = sheet.lower_bound(date);
        float BtcPrice = 0.0f;

        if (it != sheet.end() && it->first == date)
        {
            BtcPrice = val * it->second;
        }
        else if (it != sheet.begin())
        {
            --it;
            BtcPrice = val * it->second;
        }
        else
        {
            std::cout << "Error: date too early => " << date << std::endl;
            continue;
        }
        std::cout << date << " => " << val << " = " << BtcPrice << std::endl;
    }
}
