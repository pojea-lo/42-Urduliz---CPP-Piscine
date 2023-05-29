#include "PmergeMe.hpp"

//external functions
bool    ft_check (char *str) {

	std::string		aux;
	long int		num;

	aux = str;
	for (size_t j = 0; j < aux.size(); j++) {
		if (!isdigit(str[j]) || str[j] == '\'' || str[j] == '\"') {
			std::cout << "Error: '" << aux << "' Bad argument!!!" << std::endl;
			return false;
		}
	}
	num = std::atol(str);
	if (num < 0 || num > 2147483647) {
		std::cout << "Error: '" << aux << "' Bad argument!!!" << std::endl;
		return false;
	}

	return true;
}
