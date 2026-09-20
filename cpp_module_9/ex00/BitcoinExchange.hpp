#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BtcExchange
{
    private:
        std::map<std::string, float> sheet;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string &valueStr, float &value)const;
        void printExchangeValue(const std::string& date, float value) const;
    public:
        BtcExchange();
        BtcExchange(const BtcExchange& cpy);
        BtcExchange& operator=(const BtcExchange& op);
        ~BtcExchange();
        bool loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);
};

#endif