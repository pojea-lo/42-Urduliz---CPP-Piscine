#include "PmergeMe.hpp"

//canonical functions and various
PmergeMe::PmergeMe() : i_vector(), i_set() {

	return;
}

PmergeMe::PmergeMe(char **str) {

	if (ft_check(str)) {

		std::cout << "Vamos alla" << std::endl;
	}
	else {

		std::cout << "Error: Bad arguments" << std::endl;
		exit (-1);
	}

	return;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {

	*this = obj;
	return;
}

PmergeMe::~PmergeMe() {

	return;
}

PmergeMe    &PmergeMe::operator=(const PmergeMe &obj) {

	if (obj.i_vector.size() != 0 && obj.i_set.size() != 0) {
		this->i_vector = obj.i_vector;
		this->i_set = obj.i_set;
	}

	return *this;
}

//external functions
bool    ft_check (char **str) {

		


}