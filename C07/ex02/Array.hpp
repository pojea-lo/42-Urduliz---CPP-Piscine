#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <class T>

class Array {

	private:
		T	*Vec;
		size_t	size;

	public:

//constructors & destructors
		Array() : size(0) {

			std::cout << "Empty constructor was called" << std::endl;
			Vec = new T();

			return;
		}

		Array(unsigned int n) : size(n) {
			
			if (n < 0)
				throw	std::out_of_range("Out of range");

			std::cout << "Parameter constructor was called" << std::endl;
			Vec = new T[n]();
			for (size_t i = 0; i < static_cast<size_t>(n); i++)
//				Vec[i] = i;//para int
				Vec[i] = 50.02f + static_cast<float>(i);//para fixed

			return;
		}

		Array(const Array &obj) {

			std::cout << "Copy constructor was called" << std::endl;
			*this = obj;

			return;
		}

//overload operators
		Array	&operator=(const Array &obj) {
	
			std::cout << "Operator = was called" << std::endl;

			if (!obj.getSize())
				Vec = new T();
			else
			{
				Vec = new T[obj.getSize()]();
				for (size_t i = 0; i < obj.getSize(); i++)
					Vec[i] = obj.Vec[i];
			}
			size = obj.size;

			return *this;
		}

		T	&operator[](int n) { 
			
			if (n < 0 || n > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
			
			return Vec[n];
		}

//getters & setters
		size_t	getSize() const {
			
			return (this->size);
		}

		T	getVec(int pos) const {

			if (pos < 0 || pos > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
		
			return (Vec[pos]);
		}

		void	setVec(T neu, int pos) {

			if (pos < 0 || pos > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
			
			Vec[pos] = neu;

			return;
		}
};

#endif


//FIXED CLAS TO PROVE

#include <cmath>

class Fixed {

	private:
		int					res;
		const static int	rawBits = 8;

	public:
		Fixed ();
		Fixed (const int ent);
		Fixed (const float flt);
		~Fixed ();
		Fixed (const Fixed& obj);
		Fixed &operator= (const Fixed &obj);
		bool operator< (const Fixed &obj);
		bool operator> (const Fixed &obj);
		bool operator<= (const Fixed &obj);
		bool operator>= (const Fixed &obj);
		bool operator== (const Fixed &obj);
		bool operator!= (const Fixed &obj);
		Fixed operator+ (const Fixed &obj);
		Fixed &operator- (const Fixed &obj);
		Fixed operator* (const Fixed &obj);
		Fixed &operator/ (const Fixed &obj);
		Fixed &operator++ ();
		Fixed operator++ (int);
		Fixed &operator-- ();
		Fixed operator-- (int);

		int				getRawBits() const;
		void			setRawBits(const int raw);
		int				toInt() const;
		float			toFloat() const;
		static Fixed	&min(Fixed &objA, Fixed &objB);
		static Fixed	&max(Fixed &objA, Fixed &objB);
		static Fixed	min(const Fixed &objA, const Fixed &objB);
		static Fixed	max(const Fixed &objA, const Fixed &objB);



};

	std::ostream& operator<<(std::ostream& os, Fixed const &obj);

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

Fixed	Fixed::operator+ (const Fixed &obj) {

	Fixed	add(this->toFloat() + obj.toFloat());
	return (add);
}

Fixed	&Fixed::operator- (const Fixed &obj) {

	Fixed	*rest = new Fixed (this->toFloat() - obj.toFloat());
	delete rest;
	return (*rest);
}

Fixed	Fixed::operator* (const Fixed &obj) {

	return (this->toFloat() * obj.toFloat());
}

Fixed	&Fixed::operator/ (const Fixed &obj) {

	if (roundf(obj.res) / (1 << this->rawBits) == 0)
		std::cout << "Impossible division by ";
	else {
		Fixed	*div = new Fixed(this->toFloat() / obj.toFloat());
		delete div;
		return (*div);
	}
	return ((Fixed &)obj);
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
