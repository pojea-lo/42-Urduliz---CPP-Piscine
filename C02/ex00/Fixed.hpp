#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					res;
		const static int	rawBits;

	public:
		Fixed ();
		~Fixed ();
		Fixed (const Fixed& obj);
		Fixed& operator= (Fixed& obj);

		int		getRawBits() const;
		void	setRawBits(int const raw);

};

#endif
