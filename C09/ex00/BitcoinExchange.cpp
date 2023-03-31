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
	for(std::multimap<int, int>::iterator it = this->input.begin(); it != this->input.end(); it++) {
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

std::multimap<int, int> ft_createinput(char *str) {

	std::multimap<int, int>	ret;
	std::string				line;
	std::string				first_data;
	std::string				second_data;

	if (ft_check(str)) {
		std::ifstream file(str);
		file.close();
	}
	else {
		std::cout << "Bad input file" << std::endl;
		exit (1);
	}	
	return (ret);
}

bool	ft_check(char *str) {

	std::string				line;
	
	std::ifstream file(str);
	if (!file) {
		file.close();
		return false;
	}
	while (getline(file, line)) {
		std::stringstream stream(line);
		std::cout << stream << std::endl;


/*		getline(stream, first_data, ',');
		first_data.replace(4, 1, "");
		first_data.replace(6, 1, "");
		getline(stream, second_data, ',');
		ret.insert(std::pair<int, int>(std::atoi(first_data.c_str()), std::atoi(second_data.c_str())));
*/	}
	file.close();

	file.close();
	return true;
}
































