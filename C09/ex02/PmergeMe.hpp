#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <cctype>
#include <string>

class PmergeMe {

	private:
		std::vector<int>    i_vector;
		std::set<int>       i_set;

	public:
		PmergeMe();
		PmergeMe(int argc, char **str);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();

		PmergeMe    &operator=(const PmergeMe &obj);
		
		std::string		getVector();

		void			sorta();

};

std::ostream	&operator<<(std::ostream &os, PmergeMe &obj);
bool    		ft_check(char *str);

#endif
