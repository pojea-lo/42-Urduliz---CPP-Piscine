#include "RPN.hpp"

//canonical various    
RPN::RPN() : list() {

	return;    
}

RPN::RPN(char *str) {

	if (ft_check(str)) {
	
		this->list = ft_create(str);
		if (this->list.size() == 0)
			exit (-1);
	}
	else
		exit(-1);
	return;
}

RPN::RPN(const RPN &obj) {

	*this = obj;
	return;
}

RPN::~RPN() {


	return;
}

RPN &RPN::operator=(const RPN &obj) {

	this->list = obj.list;
	return *this;    
}

//class functions
void	RPN::ft_print() {

	std::stack<float>		aux(this->list);
	
	if (aux.size() != 1)
		std::cout << "Error: Something smells rotten in Denmark" << std::endl;
	else {
		while (!aux.empty()) {

			std::cout << aux.top() << std::endl;
			aux.pop();
		}
	}
	return;
}

//external functions
bool    ft_check(char *str) {

	for (size_t i = 1; i < std::strlen(str); i++) {

		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != ' ') {

			std::cout << "Error: '" << str[i] << "' Argument no number!!!" << std::endl;
			return false;
		}
	}
	
	std::string			aux = str;
	std::stringstream 	stream(aux);
	while (getline(stream, aux, ' ')) {
		if (aux.size() > 1) {

			if (!(aux[0] == '-' && isdigit(aux[1]) && aux.size() == 2)) {
				std::cout << "Error: '" << aux << "' Bad argument, number too big or more than one operator!!!" << std::endl;
				return false;
			}
		}
	}
	return true;
}

std::stack<float>  ft_create(char *str) {

	std::stack<float>	res;
	std::string			aux = str;
	std::stringstream	stream(aux);
	float				sol1;
	float				sol2;
	
	while (getline(stream, aux, ' ')) {
		if (aux.size() > 0) { //con esto evito los espacios que me dan size 0
			if ((aux[0] >= '0' && aux[0] <= '9') || (aux[0] == '-' && aux.size() == 2)) {
				res.push(std::atoi(aux.c_str()));
			}
			else {
				if (res.size() < 2) {
					std::cout << "Error: Needed at least 2 numbers in the stack for the operation" << std::endl;
					while (!res.empty())
						res.pop();
					return res;
				}
				sol1 = res.top();
				res.pop();
				sol2 = res.top();
				res.pop();
				sol1 = ft_operate(aux[0], sol2, sol1);
				res.push(sol1);
			}
		}
	}

	return res;
}

float	ft_operate(char aux, float sol2, float sol1) {

	if (aux == '+')
		return (sol2 + sol1);
	else if (aux == '-')
		return (sol2 - sol1);
	else if (aux == '*')
		return (sol2 * sol1);
	else if (aux == '/') {
		if (sol1 != 0) {
			return (sol2 / sol1);
		}
		else {
			std::cout << "Error: Impossible to divide by zero" << std::endl;
			exit (-1);
		}
	}

	return 0;
}
