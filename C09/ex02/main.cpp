#include "PmergeMe.hpp"

int     main(int argc, char **argv) {

	if (argc <= 2) {

		std::cout << "Error: I need more than 2 numbers to ordem them!!!" << std::endl;
		return -1;
	}
	else {

		PmergeMe    init(argc, argv);

		std::cout << "Before: " << init << std::endl;
		init.sorta();
		std::cout << "After: " << init << std::endl;
	}

	return 0;
}
