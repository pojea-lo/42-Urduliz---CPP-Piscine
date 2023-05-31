#include "BitcoinExchange.hpp"

int		main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: bad number of arguments" << std::endl;
		return 1;
	}
	else {
		BitcoinExchange		prueba(argv[1]);
		prueba.print_input();
	}

	return 0;
}
