#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>

const size_t		limit_sort_treshold = 5;

bool    		ft_check(char *str);

template <typename container>
class PmergeMe {

	private:
		container	i_cont;
		size_t		sort_treshold;

	public:

		typedef typename container::iterator	iter;

		PmergeMe() : i_cont() , sort_treshold(limit_sort_treshold) {

			return;
		}

		PmergeMe(int argc, char **str) {

			for (int i = 1; i < argc; i++) {
				if (ft_check(str[i]))
					this->i_cont.push_back(atoi(str[i]));

				else
					exit (-1);
			}

			this->sort_treshold = limit_sort_treshold;

			return;
		}

		PmergeMe(const PmergeMe &obj) {

			*this = obj;
			return;
		}

		~PmergeMe() {

			return;
		}

		PmergeMe    &operator=(const PmergeMe &obj) {
		
			if (obj.i_cont.size() != 0) {
				this->i_cont = obj.i_cont;
			}

			this->sort_treshold = obj.sort_treshold;

			return *this;
		}

		container		getI_cont() {

			return i_cont;
		}

		std::string		getString() {

			std::string			aux;
			std::stringstream	ss;

			for (iter it = this->i_cont.begin(); it != this->i_cont.end(); it++) {
				ss << *it;
				ss << " ";
			}
			aux.append(ss.str());

			return aux;
		}

		void		orden() {

			if (this->i_cont.size() <= this->sort_treshold)
				make_insert();				
					
			else
				std::cout << "Divido con merge" << std::endl;

			return;
		}

		void		make_insert() {
			
			int		aux;
			size_t	i = 0;

			while (i < this->i_cont.size()- 1) {

				if (this->i_cont[i] > this->i_cont[i + 1]) {
					aux = this->i_cont[i];
					this->i_cont[i] = this->i_cont[i + 1];
					this->i_cont[i + 1] = aux;
					i = 0;
				}
				else
					i++;
			}
		}
};

template <typename container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<container> &obj) {

	os << obj.getString();
	return os;
}

#endif
