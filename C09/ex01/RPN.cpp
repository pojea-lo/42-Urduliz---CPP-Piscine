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

	std::stack<int>		aux(this->list);
	
	while (!aux.empty()) {

		std::cout << aux.top() << std::endl;
		aux.pop();
	}

	return;
}

std::stack<int>  RPN::ft_create(char *str) {

	std::stack<int>		res;
	std::string			aux = str;
	std::stringstream	stream(aux);
	int					sol;
	
	while (getline(stream, aux, ' ')) {
		if (aux.size() > 0) { //con esto evito los espacios que me dan size 0
			if ((aux[0] >= '0' && aux[0] <= '9') || (aux[0] == '-' && aux.size() == 2)) {
				res.push(std::atoi(aux.c_str()));
			}
			else {
				if (res.size() != 2) {
					std::cout << "Error: Needed only 2 numbers in the stack for the operation" << std::endl;
					while (!res.empty())
						res.pop();
					return res;
				}
				sol = res.top();
				ft_operate(aux[0]);
				res.push(sol);
			}
		}
	}

	return res;
}

int	RPN::ft_operate(char aux) {

	


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
