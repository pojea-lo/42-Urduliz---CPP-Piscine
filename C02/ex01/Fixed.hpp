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

		int		getRawBits() const;
		void	setRawBits(const int raw);

		int		toInt() const;
		float	toFloat() const;

};

		std::ostream& operator<<(std::ostream& os, Fixed const &obj);

#endif
