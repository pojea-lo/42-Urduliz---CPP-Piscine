#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>
#include <sys/time.h>

const size_t		limit_sort_treshold = 5;

bool    		ft_check(char *str);

template <typename container>
class PmergeMe {

	private:
		container	i_cont;

	public:

		typedef typename container::iterator	iter;

		PmergeMe() : i_cont() {

			return;
		}

		PmergeMe(int argc, char **str) {

			for (int i = 1; i < argc; i++) {
				if (ft_check(str[i]))
					this->i_cont.push_back(atoi(str[i]));

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

			if (this->i_cont.size() <= limit_sort_treshold)
				this->i_cont = make_insert(this->i_cont);				
					
			else
				make_merge();

			return;
		}

//funcion que realiza el algoritmo de ordenacion insert
		container		make_insert(container vector) {
			
			iter 	it = vector.begin();
			int		aux;
			
			while (it != vector.end() - 1) {

				if (*(it + 1) < *it) {
					aux = *(it + 1);
					vector.erase(it + 1);
					vector.insert(it, aux);
					it = vector.begin();
				}
				else
					it++;
			}

			return vector;
		}

//función que realiza el algoritmo de merge
		void		make_merge() {

//calculo el numero de subgrupos en los que divido la lista en funcion del limite que tenga definido al inicio
			int		merge_size;
			
			if (i_cont.size() % limit_sort_treshold == 0)
				merge_size = i_cont.size() / limit_sort_treshold;
			else
				merge_size = (i_cont.size() / limit_sort_treshold) + 1;

//leno los subgrupos de numeros del array
			container	cont_aux[merge_size];
			size_t		i = 0;
			size_t		j = 0;

			for (iter it = this->i_cont.begin(); it != this->i_cont.end(); it++) {

				cont_aux[i].push_back(*it);
				j++;
				
				if (j == limit_sort_treshold) {
					i++;
					j = 0;
				}
			}

//ordeno todos los subgrupos
			for (int i = 0; i != merge_size; i++)
				cont_aux[i] = make_insert(cont_aux[i]);

//mezclo los subgrupos quedandome ya en el grupo 0 la lista ordenada
//			while (cont_aux[1].size() != 0) {

				i = 0;
				cont_aux[i] = ft_combine(cont_aux[i], cont_aux[i + 1]);
				
//			}			

		}

		container	ft_combine(container list_1, container list_2) {

			size_t		i;
			iter		it_2 = list_2.begin();

			while (list_2.size() != 0) {

				it_2 = list_2.begin();
				i = 0;

				while (i < list_1.size() && list_1[i] < *it_2) 
					i++;

				if (i != list_1.size()) {
					list_1.insert(list_1.begin() + i, *it_2);
					list_2.erase(list_2.begin());
				}
			}

			return list_1;
		}


};

template <typename container>
std::ostream	&operator<<(std::ostream &os, PmergeMe<container> &obj) {

	os << obj.getString();
	return os;
}

#endif
