#include "RPN.hpp"

//canonical various    
RPN::RPN() : list() {

	return;    
}

RPN::RPN(int argc, char **str) {

	if (ft_check(argc, str)) {
	
		std::cout << "Good" << std::endl;
		// list = ft_create(str);
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

//external functions
bool    ft_check(int argc, char **str) {

	for (int i = 1; i < argc; i++) {

		std::cout << str[i] << std::endl;
		if (std::strlen(str[i]) != 1) {

			std::cout << "Error: " << str[i] << " Argument too large!!!" << std::endl;
			return false;
		}
		else if (!isdigit(str[i][0]) && str[i][0] != '+' && str[i][0] != '-' && str[i][0] != '*' && str[i][0] != '/') {

			std::cout << "Error: " << str[i][0] << " Argument no number!!!" << std::endl;
			return false;
		} 
	}


	return true;
}

// std::stack  ft_create(const std::string &str) {



	
// }