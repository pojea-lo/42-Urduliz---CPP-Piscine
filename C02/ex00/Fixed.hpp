#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					res;
		const static int	rawBits;

	public:
		Fixed ();
		Fixed (int n);
		~Fixed ();
		Fixed (const Fixed& obj);
		Fixed operator= (Fixed& obj1);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		

};


#endif
