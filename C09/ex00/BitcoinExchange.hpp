#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define file_name "data.csv"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string>

class BitcoinExchange {

	private:
		std::map <int, int>					database;
		std::multimap <std::string, int>	input;

	public:
		BitcoinExchange();
		BitcoinExchange(char *str);
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &obj);

		void	print_db();
		void	print_input();

	
};

std::map<int, int>				ft_createdb();
std::multimap<std::string, int>	ft_createinput(char *str);
bool							ft_checkFirst(std::string *str);
bool							ft_checkSecond(std::string *str);
bool							ft_isdigit(std::string str);

#endif
