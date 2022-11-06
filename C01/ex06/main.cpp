#include "Karen.hpp"

int	main(int argv, char** argc) {

	Karen			KKaren;
	std::string		levelminus = "";
	std::string		level[4] = {"debug", "info", "warning", "error"}; 

	if (argv != 2) {
		std::cout << "Bad number of arguments!!" << std::endl;
		return -1;
	}
	levelminus = argc[1];
	for (size_t i = 0; i < levelminus.length(); i++)
		levelminus[i] = tolower(levelminus[i]);
	for (int i = 0; i < 4; i++) {
		if (level[i].compare(levelminus)) {
			KKaren.complain(levelminus);
			return 0;
		}
	}
	return 0;
}
