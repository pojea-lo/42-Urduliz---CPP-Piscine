#include "Fixed.hpp"

int	main() {

	Fixed 		a;
	Fixed const	b( Fixed(5.05f) * Fixed(2) );
//	Fixed 	b( Fixed(5.05f) * Fixed(2) );


//pruebas del Pablo
/*
	Fixed		c(9.55555555f);
	Fixed		d(4);
//	Fixed		d(9.55555555f);
//	Fixed		c(7.22222f);

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	if (c < d)
		std::cout << "La c es menor" << std::endl;
	if (c > d)
		std::cout << "La c es mayor" << std::endl;
	if (c <= d)
		std::cout << "La c es menor o igual" << std::endl;
	if (c >= d)
		std::cout << "La c es mayor o igual" << std::endl;
	if (c == d)
		std::cout << "La c es igual" << std::endl;
	if (c != d)
		std::cout << "La c es distinta" << std::endl;

	std::cout << "La suma:           " << c + d << std::endl;
	std::cout << "La resta:          " << c - d << std::endl;
	std::cout << "La multiplicación: " << c * d << std::endl;
	std::cout << "La división:       " << c / d << std::endl;
*/
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
/*	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
*/	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
/*	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
*/
	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
//	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}
