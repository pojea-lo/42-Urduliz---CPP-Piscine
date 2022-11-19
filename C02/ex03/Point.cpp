#include "Point.hpp"

//******************************************constructors & destructors
/*
Point::Point () : x(), y() {

	std::cout << "Empty constructor called" << std::endl;
	return;
}
*/
Point::Point () {

//	std::cout << "Empty constructor called" << std::endl;
	Fixed x;
	Fixed y;
	return;
}

Point::Point (float const _x, float const _y) : x(_x), y(_y) {

//	std::cout << "Complete constructor called" << std::endl;
	return;
}

Point::~Point() {

//	std::cout << "Destructor called" << std::endl;
	return;
}

Point::Point (const Point &obj) {

//	std::cout << "Copy constructor called" << std::endl;
	(Fixed &)this->x = obj.x;
	(Fixed &)this->y = obj.y;
	return;
}

//**************************************************overload functions

Point	Point::operator= (const Point &obj) {

	(Fixed &)this->x = obj.x;
	(Fixed &)this->y = obj.y;
	return (*this);
}

bool	Point::operator== (Point const &obj) {

	if ((Fixed &)this->x == (Fixed &)obj.x && (Fixed &)this->y == (Fixed &)obj.y)
		return (true);
	return (false);
}

std::ostream&	operator<<(std::ostream& os, Point const &obj) {

	os << obj.getX() << " / " << obj.getY();

	return os;
}

Point	&Point::operator+ (Point const &obj) {

	Point	*add = new Point();

	add->setX(this->getX() + obj.x);
	add->setY(this->getY() + obj.y);
	delete (add);
	return (*add);
}

Point	Point::operator- (Point const &obj) {

	Point	res;

	res.setX(this->getX() - obj.x);
	res.setY(this->getY() - obj.y);
	return (res);
}


//***************************************************getters & setters

Fixed	Point::getX() const {

	return (this->x);
}

Fixed	Point::getY() const {

	return (this->y);
}

void	Point::setX(const Fixed _x) {

	(Fixed &)this->x = _x;
	return;
}

void	Point::setY(const Fixed _y) {

	(Fixed &)this->y = _y;
	return;
}
