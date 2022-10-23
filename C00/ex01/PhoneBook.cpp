#include "PhoneBook.hpp"
#include <iostream>

//constructor and destructor

//empty contructor
PhoneBook::PhoneBook (void) {

	return;
}

PhoneBook::~PhoneBook (void) {

	return;
}

//metodos
void	PhoneBook::introDataContact (int id) {

	std::string	data;

	std::cout << "Come on, let's introduce a new Contact:" << std::endl;
	std::cout << "Please, write First Name: ";
	std::cin >> data;
	this->_list[id].setFirstName (data);
	std::cout << "Last Name: ";
	std::cin >> data;
	this->_list[id].setLastName (data);
	std::cout << "Nickname: ";
	std::cin >> data;
	this->_list[id].setNickname (data);
	std::cout << "Phone: ";
	std::cin >> data;
	this->_list[id].setPhone (data);
	std::cout << "Darkest Secret: ";
	std::cin >> data;
	this->_list[id].setDarkestSecret (data);
	return;
}

void	printSP(int n) {
	
	for (int i = 0; i < n; i++)
		std::cout << " ";

	return;
}

void	dataTrunk(std::string data) {

	int	n;

	n = data.size();
	if (n <= 9) {
		printSP(10 - n);
		std::cout << data;
	}
	else {
		for (int i = 0; i < 9; i++)
			std::cout << data[i];
		std::cout << ".";
	}

	return;
}

void	PhoneBook::printData () {

	std::cout << "/-------------------------------------------\\" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "|";
		printSP(9);
		std::cout << (i + 1) << "|";
		dataTrunk(this->_list[i].getFirstName());
		std::cout << "|";
		dataTrunk(this->_list[i].getLastName());
		std::cout << "|";
		dataTrunk(this->_list[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "\\-------------------------------------------/" << std::endl;

}

void	PhoneBook::printSingleData (int id) {

	if (id >= 0 && id < 8) {
		if (this->_list[id].getFirstName() == "")
			std::cout << "Empty contact" << std::endl;
		else {
			std::cout << "First Name: " << this->_list[id].getFirstName() << std::endl;
			std::cout << "Last Name: " << this->_list[id].getLastName() << std::endl;
			std::cout << "Nickname: " << this->_list[id].getNickname() << std::endl;
			std::cout << "Phone: " << this->_list[id].getPhone() << std::endl;
			std::cout << "Darkest secret: " << this->_list[id].getDarkestSecret() << std::endl;
		}
	}
	else
		std::cout << "Contact doesn't exists" << std::endl;

	return;
}

void	PhoneBook::search (int	id) {

	std::cout << "La id es: " << id << std::endl;
}
