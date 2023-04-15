#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>
#include <sys/time.h>

bool    		ft_check(char *str);

template <typename container>
class PmergeMe {

	private:
		container	i_cont;
		double		diff;

	public:

		typedef typename container::iterator	iter;

		PmergeMe() : i_cont(), diff(0) {

			return;
		}

		PmergeMe(int argc, char **str) : diff(0) {

			for (int i = 1; i < argc; i++) {
				if (ft_check(str[i])) {

					if (std::find(this->i_cont.begin(), this->i_cont.end(), atoi(str[i])) == this->i_cont.end())
						this->i_cont.push_back(atoi(str[i]));
					else
					std::cout << "This data '" << str[i] << "' is duplicated. I delete it!!!" << std::endl;
				}
				else
					exit (-1);
			}

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
			else
				this->i_cont();
			
			this->diff = obj.diff; 

			return *this;
		}

		container		getI_cont() {

			return i_cont;
		}

		double			getDiff() {

			return (diff * 1e6);
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

			std::set<int>	aux1;
			std::set<int>	aux2;
			clock_t			init;
			clock_t			fin;

			init = clock();
			
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
			while (!aux2.empty()) {
				std::set<int>::iterator it2 = aux2.begin();
				i_cont.push_back(*it2);
				aux2.erase(it2);
			}
			
			fin = clock();
			this->diff = (double)(fin - init) / CLOCKS_PER_SEC;

			return;
		}
};

template <typename container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<container> &obj) {

    os << obj.getString();
    return os;
}

#endif
