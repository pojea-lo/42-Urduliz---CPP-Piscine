#include "TFunctions.hpp"

int		main() {

	int			a = 3;
	int			b = 2;
	char		c = 'a';
	char		d = 'b';
	std::string	e = "Stich";
	std::string	f = "Lilo";

	std::cout << "\n_______SWAP__________________________________________\n" << std::endl;
	std::cout << "Before swap - a: " << a << "   b: " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  - a: " << a << "   b: " << b << std::endl;
	std::cout << "Before swap - c: " << c << "   d: " << d << std::endl;
	swap(c, d);
	std::cout << "After swap  - c: " << c << "   d: " << d << std::endl;
	std::cout << "Before swap - e: " << e << "   f: " << f << std::endl;
	swap(e, f);
	std::cout << "After swap  - e: " << e << "   f: " << f << std::endl;

	std::cout << "\n_______RETURN TO THE BEGINNING_______________________\n" << std::endl;
	swap(a, b);
	std::cout << "a: " << a << "   b: " << b << std::endl;
	swap(c, d);
	std::cout << "c: " << c << "   d: " << d << std::endl;

	std::cout << "\n_______MAX___________________________________________\n" << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << max(c, d) << std::endl;
//	std::cout << max(e, f) << std::endl;

	std::cout << "\n_______MIN___________________________________________\n" << std::endl;
	std::cout << min(a, b) << std::endl;
	std::cout << min(c, d) << std::endl;
//	std::cout << min(e, f) << std::endl;

	return 0;
}