#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>  
#include <string>
#include <climits>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void ReadDatabase();
        void PrintDatabase();
        void ReadInput(std::string filename);
        int splitString(std::string line);
        int ParseInput(int year, int month, int day, double value, std::string line);
        void PrintOutput(std::string input, double value);
};

#endif