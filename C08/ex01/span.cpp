#include "span.hpp"

//constructors and destructors
Span::Span() : test(0) , id(0), nelem(0){

	std::cout << "Empty constructor was called" << std::endl;
	return;
}

Span::Span(unsigned int n): id(0), nelem(n) {

	std::cout << "Parameter constructor was called" << std::endl;
	test.reserve(n);
	return;
}

Span::Span(const Span &obj) {

	std::cout << "Copy constructor was called" << std::endl;
	id = obj.id;
	nelem = obj.nelem;
	for (size_t i = 0; i < sizeof(obj) / sizeof(int); i++)
		test[i] = obj.test[i];
	return;
}

Span::~Span() {

	std::cout << "Destructor was called" << std::endl;
	return;
}

//getters & setters
int		Span::getTest(size_t n) const {

	return test[n];
}

size_t	Span::getId() const {

	return id;
}

size_t	Span::getNelem() const {

	return nelem;
}

//overload operators
Span	&Span::operator=(const Span &obj) {

	std::cout << "Overload = was called" << std::endl;
	id = obj.id;
	nelem = obj.nelem;
	for (size_t i = 0; i < sizeof(obj) / sizeof(int); i++)
		test[i] = obj.test[i];
	return *this;
}

int		&Span::operator[](unsigned int n) {

	if (n >= nelem) {
		throw std::out_of_range ("Out of range");
	}
	return test[n];
}

//methods
void	Span::addNumber(int n) {

	if (id < nelem) {
		test[id] = n;
		id++;
	}
	else
		throw std::out_of_range("Vector full!!");
	return;
}

int	Span::shortestSpan() {

	if (id < 2)
		throw std::out_of_range("Insufficient number of nodes");

	size_t	i = 0;
	int		aux = 0;

	std::cout << id << std::endl;
	while (i < id - 1) {

		if (test[i] > test[i + 1]) {
			aux = test[i];
			test[i] = test[i + 1]; 
			test[i + 1] = aux;
		}
		i++;
	}
	return (test[1] - test[0]);
}

int	Span::longestSpan() {

	if (id < 2)
		throw std::out_of_range("Insufficient number of nodes");

	int		max = test[0];
	int		min = test[0];

	for (size_t i = 0; i < id; i++) {
		if (test[i] < min)
			min = test[i];
		else if (test[i] > max)
			max = test[i];
	}
	
	return (max - min);
}