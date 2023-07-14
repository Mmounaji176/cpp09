#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>  
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void ReadDatabase();
        void PrintDatabase();
        void ReadInput(std::string filename);
        int splitString(std::string line);
        int ParseInput(int year, int month, int day, float value, std::string line);
        void PrintOutput(std::string input, float value);
};

#endif