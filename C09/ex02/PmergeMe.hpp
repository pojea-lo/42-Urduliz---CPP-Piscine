#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

class PmergeMe {

	private:
		std::vector<int>    i_vector;
		std::set<int>       i_set;

	public:
		PmergeMe();
		PmergeMe(char **str);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();

		PmergeMe    &operator=(const PmergeMe &obj);


};

bool    ft_check(char **str);

#endif