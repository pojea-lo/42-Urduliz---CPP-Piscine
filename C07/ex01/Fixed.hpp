#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
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

#endif
