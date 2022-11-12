#include "Karen.hpp"

#include <iostream>

//constructor and destructor
Karen::Karen() {

	return;
}

Karen::~Karen() {

	return;
}

//privates functions
void	Karen::debug() {

	std::cout << "DEBUG - I love Karen but..." << std::endl;
	return;
}

void	Karen::info() {

	std::cout << "INFO - I love Karen but sometimes..." << std::endl;
	return;
}

void	Karen::warning() {

	std::cout << "WARN - Maybe Karen is not so good!!!" << std::endl;
	return;
}

void	Karen::error() {

	std::cout << "ERNO - Fucking Karen, always the same" << std::endl;
	return;
}

//methods
void	Karen::complain(std::string level) {

	std::string		list[4] = {"debug", "info", "warning", "error"};
	void			(Karen::*ptrFun[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	int				i = 0;
	
	while (level.compare(list[i]) != 0 && i < 4)
		i++;
	(this->*ptrFun[i])();
	return;
}
