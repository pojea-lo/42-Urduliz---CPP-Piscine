#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>

template <typename container>
class PmergeMe {

	private:
		container    i_cont;

	public:
		PmergeMe();
		PmergeMe(int argc, char **str);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();

		PmergeMe    &operator=(const PmergeMe &obj);
		
		container		getI_cont();
		std::string		getString();

/*		void		orden(container i_cont) {

			std::set<int>	aux1;
			std::set<int>	aux2;

			for (size_t i = 0; i < (i_cont.size() / 2); i++)
				aux1.insert(i_cont[i]);
			for (size_t i = (i_cont.size() / 2); i < i_cont.size(); i++)
				aux2.insert(i_cont[i]);

			while (!i_cont.empty())
				i_cont.pop_back();

			while (!aux1.empty()) {

				std::set<int>::iterator it1 = aux1.begin();
				if (!aux2.empty()) {

					std::set<int>::iterator it2 = aux2.begin();
					if (*it1 < *it2) {
						i_cont.push_back(*it1);
						aux1.erase(it1);
					}
					else {
						i_cont.push_back(*it2);
						aux2.erase(it2);
					}
				}
				else {
					i_cont.push_back(*it1);
					aux1.erase(it1);
				}
			}
			return;
		}
*/
};

template <typename container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<container> &obj) {

    os << obj.getString();
    return os;
}

bool    		ft_check(char *str);

#endif
