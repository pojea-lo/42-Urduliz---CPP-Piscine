#include "PmergeMe.hpp"

int     main(int argc, char **argv) {

	if (argc <= 2) {

		std::cout << "Error: I need more than 2 numbers to ordem them!!!" << std::endl;
		return -1;
	}
	else {

		PmergeMe    init(argv);
	}

	return 0;
}