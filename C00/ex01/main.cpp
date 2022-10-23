#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	ft_responseControl (std::string str) {
	
    for (size_t i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i]) == 0)
			return (-1);
    }
    return (0);
}



int	main(void) {

	std::string	response;
	bool		answ = true;
	int			id = 0;
	int			n = 0;
	PhoneBook	list;

	do {
		std::cout << "\nWhat do you want to do:" << std::endl;
		std::cout << " (A) ADD - a new contact" << std::endl;
		std::cout << " (S) SEARCH - a contact" << std::endl;
		std::cout << " (E) EXIT - of the program\n";
		std::cin >> response;
		std::cout << std::endl;
		if (response.compare("ADD") != 0 && response.compare("SEARCH") != 0 && response.compare("EXIT") != 0 && response.compare("A") != 0 && response.compare("S") != 0 && response.compare("E") != 0) 
			std::cout << "\nResponse incorrect!!, try again" << std::endl;
		else {
			if (response.compare("ADD") == 0 || response.compare("A") == 0) {
				list.introDataContact(id);
				if (id == 7)
					id = -1;
				id++;
			}
			else if (response.compare("SEARCH") == 0 ||	response.compare("S") == 0) {
					list.printData();
				std::cout << "Who want's to search: ";
				std::cin >> response;
				if (ft_responseControl (response) == -1)
					std::cout << "Wrong answer" << std::endl;
				else {
					n = stoi(response);
					list.printSingleData(n - 1);
				}
			}
			else if (response.compare("EXIT") == 0 || response.compare("E") == 0) {
				answ = false;
			}
		}
	} while (answ == true);

	return (0);
}
