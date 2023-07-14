#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cout << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.ReadDatabase();
    // exchange.PrintDatabase();
    exchange.ReadInput(av[1]);
    return 0;
}