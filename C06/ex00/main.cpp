#include "Auxiliar.hpp"

#include <string>
#include <iomanip>

int	main(int argc, char *argv[]) {

	std::string		char_tmp;
	std::string		argument;


	try {

		if (argc != 2) {
			throw 1;
			return -1;
		}
		argument = static_cast<std::string> (argv[1]);
		
//char cast	
	
		Auxiliar	one;

		char_tmp = one.check(argument);

		try {
			if (char_tmp.compare("one") == 0) 
				std::cout << "My char cast:       " << argv[1][0] << std::endl;
			else if (char_tmp.compare("ok") == 0) 
				std::cout << "My char cast:       " << static_cast<char> (std::stoi(argument)) << std::endl;
			else 
				std::cout << "My char cast:       " << char_tmp << std::endl;
		}
		
		catch (std::exception &ex) {
			std::cout << "impossible" << std::endl;
		}


//int cast

		try {
			std::cout << "My int cast:        " << std::stoi(argument) << std::endl;
		}	
		
		catch (std::exception &ex) {
			std::cout << "impossible" << std::endl;
		}

//float cast

		std::cout << std::fixed; 
		std::cout << std::setprecision(one.count(argument));
		try {
			std::cout << "My float cast:      " << std::stof(argument) << "f" << std::endl;
		}	
		
		catch (std::exception &ex) {
			std::cout << "impossible" << std::endl;
		}

//double cast

		try {
			std::cout << "My double cast:     " << std::stod(argument) << std::endl;
		}	
		
		catch (std::exception &ex) {
			std::cout << "impossible" << std::endl;
		}
	}

	catch (int i) {

		if (i == 1)
			std::cout << "Bad number of arguments" << std::endl;
	}

	return 0;
}
