#include "Fixed.hpp"

//constructor, destructor & copy constructor
Fixed::Fixed () {
	
//	std::cout << "Default constructor called" << std::endl;
	this->res = 0;
	return;
}

Fixed::Fixed (const int ent) {

//	std::cout << "Int constructor called" << std::endl;
	this->res = ent << this->rawBits;
	return;
}

Fixed::Fixed (const float flt) {

//	std::cout << "Float constructor called" << std::endl;
	this->res = roundf (flt * (1 << this->rawBits));
	return;
}

Fixed::~Fixed () {

//	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed (const Fixed& obj) {

//	std::cout << "Copy constructor called" << std::endl;
	res = obj.getRawBits();
	return;
}

//getters & setters
int	Fixed::getRawBits() const {

//	std::cout << "getRawBits member function called" << std::endl;
	return (this->res);
}

void Fixed::setRawBits(const int raw) {

//	std::cout << "setRawBits member function called" << std::endl;
	this->res = raw;
	return;
}

//operator overload
Fixed	&Fixed::operator= (const Fixed &obj) {

//	std::cout << "Assignation operator called" << std::endl;
	this->res = obj.getRawBits();
	return (*this);
}

float	Fixed::operator+ (const Fixed &obj) {

	float	result = 0;
	result = this->res + obj.res;
	return roundf(result) / (1 << this->rawBits);
}

float	Fixed::operator- (const Fixed &obj) {

	float	result = 0;
	result = this->res - obj.res;
	return roundf(result) / (1 << this->rawBits);
}

float	Fixed::operator* (const Fixed &obj) {

	float	result = 0;
	result = this->res * obj.res;
	return roundf(result) / (1 << (this->rawBits * 2));
}

float	Fixed::operator/ (const Fixed &obj) {

	if (roundf(obj.res) / (1 << this->rawBits) == 0) {
		std::cout << "Impossible division by ";
		return 0;
	}
	float	result = 0;
	result = toFloat() / (roundf(obj.res) / (1 << this->rawBits));
	return (result);
}

Fixed	&Fixed::operator++ () {

	this->res ++;
	return (*this);
}

Fixed	Fixed::operator++ (int) {

	Fixed	aux = *this;
	this->res ++;
	return (aux);
}

Fixed	&Fixed::operator-- () {

	this->res --;
	return (*this);
}

Fixed	Fixed::operator-- (int) {

	Fixed	aux = *this;
	this->res --;
	return (aux);
}

bool	Fixed::operator< (const Fixed &obj) {

	return this->res < obj.res;
}

bool	Fixed::operator> (const Fixed &obj) {

	return this->res > obj.res;
}

bool	Fixed::operator<= (const Fixed &obj) {

	return this->res <= obj.res;
}

bool	Fixed::operator>= (const Fixed &obj) {

	return this->res >= obj.res;
}

bool	Fixed::operator== (const Fixed &obj) {

	return this->res == obj.res;
}

bool	Fixed::operator!= (const Fixed &obj) {

	return this->res != obj.res;
}

std::ostream&	operator<<(std::ostream& os, Fixed const &obj) {

	os << obj.toFloat();
	return (os);
}

//member functions
int		Fixed::toInt() const {

	int dres = this->res / (1 << this->rawBits);
	return dres;
}

float	Fixed::toFloat() const {

	float fres = roundf(this->res) / (1 << this->rawBits);
	return fres;
}

Fixed	&Fixed::min(Fixed &objA, Fixed &objB) {

	if (objA.res < objB.res)
		return (objA);
	return (objB);
}

Fixed	&Fixed::max(Fixed &objA, Fixed &objB) {

	if (objA.res > objB.res)
		return (objA);
	return (objB);
}

Fixed	Fixed::min(Fixed const &objA, Fixed const &objB) {

	if ((Fixed &)objA < (Fixed &)objB)
		return (objA);
	return (objB);
}

Fixed	Fixed::max(Fixed const &objA, Fixed const &objB) {

	if ((Fixed &)objA > (Fixed &)objB)
		return (objA);
	return (objB);
}
