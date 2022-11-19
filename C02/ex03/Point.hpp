#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		Fixed const		x;
		Fixed const		y;

	public:
		Point	();
		Point	(float const _x, float const _y);
		~Point	();
		Point	(const Point &obj);
		Point	operator= (const Point &obj);	
		bool	operator== (Point const &obj);	
		Point	&operator+ (const Point &obj);	
		Point	operator- (const Point &obj);	
		
		Fixed	getX() const;
		Fixed	getY() const;
		void	setX(const Fixed _x);
		void	setY(const Fixed _y);
};

		std::ostream	&operator<<(std::ostream& os, Point const &obj);

		bool	bsp(Point const A, Point const B, Point const C, Point const P);
#endif
