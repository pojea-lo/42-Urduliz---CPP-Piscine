#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define file_name "data.csv"

#include <iostream>
#include <fstream>
#include <sstream>


#include <map>

class BitcoinExchange {

	private:
		std::map <int, int>			database;
		std::multimap <int, int>	input;

	public:
		BitcoinExchange();
		BitcoinExchange(char *str);
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange &obj);

		void	print_db();
		void	print_input();

	




};

std::map<int, int>		ft_createdb();
std::multimap<int, int>	ft_createinput(char *str);
bool					ft_check(char *str);

#endif
