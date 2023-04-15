#include "PmergeMe.hpp"

int     main(int argc, char **argv) {

	if (argc <= 2) {

		std::cout << "Error: I need more than 2 numbers to ordem them!!!" << std::endl;
		return -1;
	}
	else {

		PmergeMe<std::vector<int> >		init_v(argc, argv);
		PmergeMe<std::deque<int> >		init_d(argc, argv);

		std::cout << "Before: " << init_v << std::endl;
		init_v.orden();
		init_d.orden();
		std::cout << "After:  " << init_v << std::endl;

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vactor<int> : " << init_v.getDiff() << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque<int>  : " << init_d.getDiff() << " us" << std::endl;
	}

	return 0;
}
