#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					res;
		const static int	rawBits;

	public:
		Fixed ();
		Fixed (const int ent);
		Fixed (const float flt);
		~Fixed ();
		Fixed (const Fixed& obj);
		Fixed &operator= (Fixed const &obj);
		void &operator<< (Fixed const &obj);

		int		getRawBits() const;
		void	setRawBits(const int raw);
		int		toInt() const;
		float	foFloat() const;

		

};


#endif
