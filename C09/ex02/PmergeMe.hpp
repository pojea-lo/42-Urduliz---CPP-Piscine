#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>

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
		
		std::vector<int>		getVector();
		std::string				getVec();

		template <typename T>
		void			orden(T container) {

			std::set<int>	aux1;
			std::set<int>	aux2;

			for (size_t i = 0; i < (container.size() / 2); i++)
				aux1.insert(container[i]);
			for (size_t i = (container.size() / 2); i < container.size(); i++)
				aux2.insert(container[i]);

			while (!container.empty())
				container.pop_back();

			while (!aux1.empty()) {

				std::set<int>::iterator it1 = aux1.begin();
				if (!aux2.empty()) {

					std::set<int>::iterator it2 = aux2.begin();
					if (*it1 < *it2) {
						container.push_back(*it1);
						aux1.erase(it1);
					}
					else {
						container.push_back(*it2);
						aux2.erase(it2);
					}
				}
				else {
					container.push_back(*it1);
					aux1.erase(it1);
				}
			}
			return;
		}

};

std::ostream	&operator<<(std::ostream &os, PmergeMe &obj);
bool    		ft_check(char *str);

#endif
