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
		std::map <int, float>						database;
		std::multimap <std::string, std::string>	input;

	public:
		BitcoinExchange();
		BitcoinExchange(char *str);
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &obj);

		void	print_db();
		void	print_input();
		double	change(std::string str1, std::string str2);
};

std::map<int, float>					ft_createdb();
std::multimap<std::string, std::string>	ft_createinput(char *str);
bool									ft_checkFirst(std::string *str);
bool									ft_checkSecond(std::string *str);
bool									ft_isdigit(std::string str);

#endif