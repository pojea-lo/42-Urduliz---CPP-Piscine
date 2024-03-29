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
//Función que me imprime la base de datos junto con su tamaño
void	BitcoinExchange::print_db() {

	std::cout << "The database for the change is: " << std::endl;
	for(std::map<int, float>::iterator it = this->database.begin(); it != this->database.end(); it++) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
	std::cout << "The size of the database is: " << this->database.size() << std::endl;
	return;
}

//Función que me imprime el archivo ya con la resolución del valor del bitcoin al cambio (usando la funcion change)
void	BitcoinExchange::print_input() {

	std::cout << "The input is: " << std::endl;
	for(std::multimap<std::string, std::string>::iterator it = this->input.begin(); it != this->input.end(); it++) {
		if (it->first.find("Error") != std::string::npos)
			std::cout << it->first << std::endl; 
		else {
			if (it->second.find("Error") != std::string::npos)
				std::cout << it->first << " -> " << it->second << std::endl;
			else {
				std::cout << it->first << " -> " << it->second << " = " << this->change(it->first, it->second) << std::endl;
			}
		}
	}
	std::cout << "The size of the input is: " << this->input.size() << std::endl;
	return;
}

//Función que busca cada posicion del archivo en la base de datos, y retorna el valor 
double	BitcoinExchange::change(std::string str1, std::string str2) {

	str1.replace(4, 1, "");
	str1.replace(6, 1, "");
	std::map<int, float>::iterator	itlow = this->database.lower_bound(std::atoi(str1.c_str()));
	std::map<int, float>::iterator	itgood;

//he de eliminar un espacio al final del str1 para compararlo con la fecha de la base de datos, pues si es la misma, me he de quedar con el low y si no coger el anterior
	str1.erase(std::remove_if(str1.begin(), str1.end(), ::isspace), str1.end());
	if (str1.compare(std::to_string(itlow->first)) != 0)
		itgood = std::prev(itlow);
	else
		itgood = itlow;

	return (std::atof(str2.c_str()) * itgood->second);
}

//external functions
//a partir del archivo de la base de datos creo el mapa
std::map<int, float>	ft_createdb() {

	std::map<int, float>	ret;
	std::string				line;
	std::string				first_data;
	std::string				second_data;

	std::ifstream file(file_name);

	getline(file, line);
	while (getline(file, line)) {
		std::stringstream	stream(line);

		getline(stream, first_data, ',');
		first_data.replace(4, 1, "");
		first_data.replace(6, 1, "");
		getline(stream, second_data, ',');
		ret.insert(std::pair<int, float>(std::atoi(first_data.c_str()), std::atof(second_data.c_str())));
	}
	file.close();
	
	return (ret);
}

//a partir del archivo de entrada creo el multimap
std::multimap<std::string, std::string> ft_createinput(char *str) {

	std::multimap<std::string, std::string>	ret;
	std::string								line;
	std::string								first_data;
	std::string								second_data;
	bool									aux;

	std::ifstream	file(str);

	if (!file) {
		file.close();
		std::cout << "No input file" << std::endl;
		exit (1);
	}
	getline(file, line);
	while (getline(file, line)) {
		std::stringstream	stream(line);

		getline(stream, first_data, '|');
		aux = ft_checkFirst(&first_data);
		if (aux) {
			getline(stream, second_data, '\n');
			ft_checkSecond(&second_data);
		}
		else {
			second_data = "";
		}
	 	ret.insert(std::pair<std::string, std::string>(first_data, second_data));
	}
	file.close();
	return (ret);
}

//chequeo el segundo argumento del map y multimap
bool	ft_checkSecond(std::string *str) {

	int		i = 0;

	while ((*str)[i] == ' ')
		i++;
	str->replace(0, i, "");
	for (size_t i = 0; i < str->size(); i++) {
		if (!(isdigit((*str)[i])) && (*str)[i] != '.') {
			(*str) = str->append(" -> Error: bad amount input");
			return false;
		}   
	}
	if (std::atof(str->c_str()) > 1000.0) {
			(*str) = str->append(" -> Error: bad amount input");
			return false;
		}   
	return true;
}

//chequeo el primer argumento de la fecha
bool	ft_checkFirst(std::string *str) {

	std::string		aux;

	if (str->size() != 11 || (*str)[4] != '-' || (*str)[7] != '-' || (*str)[10] != ' ') {
		(*str) = str->append(" -> Error: bad date input");
		return (false);
	}
	for (size_t i = 0; i < str->size(); i++) {
		if (!(isdigit ((*str)[i])) && ((*str)[i] != '-') && ((*str)[i] != ' ')) {
			(*str) = str->append(" -> Error: bad date input");
			return (false);
		}
	}
	aux = str->substr(0, 4);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 2009) || (std::atoi(aux.c_str()) > 2023)) {
		(*str) = str->append(" -> Error: bad date input");
		return (false);
	}
	aux = str->substr(5, 2);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 1) || (std::atoi(aux.c_str()) > 12)) {
		(*str) = str->append(" -> Error: bad date input");
		return (false);
	}
	aux = str->substr(8, 2);
	if (!(ft_isdigit(aux)) || (std::atoi(aux.c_str()) < 1) || (std::atoi(aux.c_str()) > 31)) {
		(*str) = str->append(" -> Error: bad input");
		return (false);
	}
	return (true);
}

//funcion que chequea si es digito para poder hacer el atoi
bool	ft_isdigit(std::string str) {
	
	for (size_t i = 0; i < str.size(); i++) {
		if (!(isdigit (str[i])))
			return false;
	}
	return true;
}
