#include "Fixed.hpp"

//const static res
int const Fixed::rawBits = 8;

//constructor, destructor & copy constructor
Fixed::Fixed () {
	
	std::cout << "Default constructor called" << std::endl;
	res = 0;
	return;
}

Fixed::~Fixed () {

	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed (const Fixed& obj) {

	std::cout << "Copy constructor called" << std::endl;
	res = obj.getRawBits();
	return;
}

//getters & setters
int	Fixed::getRawBits() const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->res;
}

void Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->res = raw;
	return;
}

//operator overload
Fixed& Fixed::operator= (Fixed& obj) {

	std::cout << "Assignation operator called" << std::endl;
	this->res = obj.getRawBits(); 
	return obj;
}
