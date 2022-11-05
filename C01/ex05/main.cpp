#include "Karen.hpp"

int	main() {

	Karen		KKaren;
	char		resp;
	std::string	resps = "";
	std::string	level = "";

	start:
	std::cout << "\nLet's see how angry Karen is. Please type level of angry:\n";
	std::cout << " A - Debug\n";
	std::cout << " B - Info\n";
	std::cout << " C - Warning\n";
	std::cout << " D - Error\n";
	std::cout << " E - Exit\n";
	std::cin >> resps;
	resp = resps[0];
	switch (toupper (resp)) {
		case 'A':
			level = "debug";
			KKaren.complain(level);
			goto start;
		case 'B':
			level = "info";
			KKaren.complain(level);
			goto start;
		case 'C':
			level = "warning";
			KKaren.complain(level);
			goto start;
		case 'D':
			level = "error";
			KKaren.complain(level);
			goto start;
		case 'E':
			std::cout << "Thank you, by by\n";
			break;
		default:
			std::cout << "Bad response, try again\n";
			goto start;
	}
	
	return 0;
}
