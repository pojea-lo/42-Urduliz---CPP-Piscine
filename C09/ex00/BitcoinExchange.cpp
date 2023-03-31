#include "BitcoinExchange.hpp"

//constructors & destructors
BitcoinExchange::BitcoinExchange() : database(ft_createdb()), input() {

//	std::cout << "Empty contructor was called" << std::endl;
	return;
}

BitcoinExchange::BitcoinExchange(char *str) {

//	std::cout << "Parametrice contructor was called" << std::endl;
	this->database = ft_createdb();
	this->input = ft_createinput(str);
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {

//	std::cout << "Copy contructor was called" << std::endl;
	*this = obj;
	return;
}

BitcoinExchange::~BitcoinExchange() {
	
//	std::cout << "Empty destructor was called" << std::endl;
	return;
}

//operator = overload
BitcoinExchange		&BitcoinExchange::operator=(const BitcoinExchange &obj) {

	this->database = obj.database;
	this->input = obj.input;
	return *this;
}

//functions
void	BitcoinExchange::print_db() {

	std::cout << "The database for the change is: " << std::endl;
	for(std::map<int, int>::iterator it = this->database.begin(); it != this->database.end(); it++) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
	std::cout << "The size of the database is: " << this->database.size() << std::endl;
	return;
}

void	BitcoinExchange::print_input() {

	std::cout << "The input is: " << std::endl;
	for(std::multimap<std::string, int>::iterator it = this->input.begin(); it != this->input.end(); it++) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
	std::cout << "The size of the input is: " << this->input.size() << std::endl;
	return;
}

//external functions
std::map<int, int>	ft_createdb() {

	std::map<int, int>	ret;
	std::string			line;
	std::string			first_data;
	std::string			second_data;

	std::ifstream file(file_name);
	getline(file, line);
	while (getline(file, line)) {
		std::stringstream stream(line);
		getline(stream, first_data, ',');
		first_data.replace(4, 1, "");
		first_data.replace(6, 1, "");
		getline(stream, second_data, ',');
		ret.insert(std::pair<int, int>(std::atoi(first_data.c_str()), std::atoi(second_data.c_str())));
	}
	file.close();
	return (ret);
}

std::multimap<std::string, int> ft_createinput(char *str) {

	std::multimap<std::string, int>	ret;
	std::string						line;
	std::string						first_data;
	std::string						second_data;
	bool							aux;

	std::ifstream file(str);
	if (!file) {
		file.close();
		std::cout << "No input file" << std::endl;
		exit (1);
	}
	while (getline(file, line)) {
		std::stringstream stream(line);
		getline(stream, first_data, '|');
		aux = ft_checkFirst(&first_data);
		// std::cout << first_data << std::endl;
		getline(stream, second_data, '\n');
		if (aux) {
			ft_checkSecond(&second_data);
			// std::cout << second_data << std::endl;
		}
		else
			second_data = "KK";
	}


	file.close();
	return (ret);
}

bool	ft_checkSecond(std::string *str) {

	int		i = 0;

	while ((*str)[i] == ' ')
		i++;
	str->replace(0, i, "");
	for (size_t i = 0; i < str->size(); i++) {
		if (!(isdigit((*str)[i])) && (*str)[i] != '.') {
			(*str) = "-7";
			return false;
		}   
	}
	std::cout << std::atof(str->c_str()) << std::endl;
	if (std::atof(str->c_str()) < 0 || std::atof(str->c_str()) > 1000) {
			(*str) = "-7";
			return false;
		}   
	return true;
}

bool	ft_checkFirst(std::string *str) {

	std::string		aux;

	if ((*str) == "date ")
		return (false);
	if (str->size() != 11 || (*str)[4] != '-' || (*str)[7] != '-' || (*str)[10] != ' ') {
		(*str) = str->append(" - Error: bad input");
		return (false);
	}
	for (size_t i = 0; i < str->size(); i++) {
		if (!(isdigit ((*str)[i])) && ((*str)[i] != '-') && ((*str)[i] != ' ')) {
			(*str) = str->append(" - Error: bad input");
			return (false);
		}
	}
	aux = str->substr(0, 4);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 2009) || (std::atoi(aux.c_str()) > 2023)) {
		(*str) = str->append(" - Error: bad input");
		return (false);
	}
	aux = str->substr(5, 2);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 1) || (std::atoi(aux.c_str()) > 12)) {
		(*str) = str->append(" - Error: bad input");
		return (false);
	}
	aux = str->substr(8, 2);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 1) || (std::atoi(aux.c_str()) > 31)) {
		(*str) = str->append(" - Error: bad input");
		return (false);
	}
	return (true);
}

bool	ft_isdigit(std::string str) {
	
	for (size_t i = 0; i < str.size(); i++) {
		if (!(isdigit (str[i])))
			return false;
	}
	return true;
}

