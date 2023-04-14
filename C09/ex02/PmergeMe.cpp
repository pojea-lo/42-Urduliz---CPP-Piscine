#include "PmergeMe.hpp"

//canonical functions and various
PmergeMe::PmergeMe() : i_vector(), i_set() {

	return;
}

PmergeMe::PmergeMe(int argc, char **str) {

	for (int i = 1; i < argc; i++) {
		if (ft_check(str[i])) {

			if (std::find(this->i_vector.begin(), this->i_vector.end(), atoi(str[i])) == this->i_vector.end())
				this->i_vector.push_back(atoi(str[i]));
			else
				std::cout << "This data '" << str[i] << "' is duplicated. I delete it!!!" << std::endl;
		}
		else 
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

std::vector<int>	PmergeMe::getVector() {

	return i_vector;
}

std::string		PmergeMe::getVec() {

	std::string			aux;
	std::stringstream	ss;

	for (std::vector<int>::iterator it = this->i_vector.begin(); it != this->i_vector.end(); ++it) {
		ss << *it;
		ss << " ";
	}
	aux.append(ss.str());

	return aux;
}

PmergeMe    &PmergeMe::operator=(const PmergeMe &obj) {

	if (obj.i_vector.size() != 0 && obj.i_set.size() != 0) {
		this->i_vector = obj.i_vector;
		this->i_set = obj.i_set;
	}

	return *this;
}

//class functions
std::ostream	&operator<<(std::ostream &os, PmergeMe &obj) {

    os << obj.getVec();
    return os;
}
/*
template <typename T>
void	PmergeMe::orden(T container) {

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
*/
//external functions
bool    ft_check (char *str) {

	std::string		aux;
	long int		num;

	aux = str;
	for (size_t j = 0; j < aux.size(); j++) {
		if (!isdigit(str[j])) {
			std::cout << "Error: '" << aux << "' Bad argument!!!" << std::endl;
			return false;
		}
	}
	num = std::atol(str);
	if (num < 0 || num > 2147483647) {
		std::cout << "Error: '" << aux << "' Bad argument!!!" << std::endl;
		return false;
	}

	return true;
}
