#include "TFunctions.hpp"

int		main() {

	int			a = 3;
	int			b = 2;
	char		c = 'a';
	char		d = 'b';
	std::string	e = "Stich";
	std::string	f = "Lilo";
	Fixed		g = 42.4242f;
	Fixed		h = 84.8484f;

	std::cout << "\n_______SWAP__________________________________________\n" << std::endl;
	std::cout << "Before swap - a: " << a << "   b: " << b << std::endl;
	swap(a, b);
	std::cout << "After swap  - a: " << a << "   b: " << b << std::endl;
	std::cout << "\nBefore swap - c: " << c << "   d: " << d << std::endl;
	swap(c, d);
	std::cout << "After swap  - c: " << c << "   d: " << d << std::endl;
	std::cout << "\nBefore swap - e: " << e << "   f: " << f << std::endl;
	swap(e, f);
	std::cout << "After swap  - e: " << e << "   f: " << f << std::endl;
	std::cout << "\nBefore swap - g: " << g << "   h: " << h << std::endl;
	swap(g, h);
	std::cout << "After swap  - g: " << g << "   h: " << h << std::endl;

	std::cout << "\n_______RETURN TO THE BEGINNING_______________________\n" << std::endl;
	swap(a, b);
	std::cout << "a: " << a << "   b: " << b << std::endl;
	swap(c, d);
	std::cout << "\nc: " << c << "   d: " << d << std::endl;
	swap(e, f);
	std::cout << "\ne: " << e << "   f: " << f << std::endl;
	swap(g, h);
	std::cout << "\ng: " << g << "   h: " << h << std::endl;


	std::cout << "\n_______MAX___________________________________________\n" << std::endl;
	std::cout << ::max(a, b) << "\n" << std::endl;
	std::cout << ::max(c, d) << "\n" << std::endl;
	std::cout << ::max(e, f) << "\n" << std::endl;
	std::cout << ::max(g, h) << "\n" << std::endl;

	std::cout << "\n_______MIN___________________________________________\n" << std::endl;
	std::cout << ::min(a, b) << "\n" << std::endl;
	std::cout << ::min(c, d) << "\n" << std::endl;
	std::cout << ::min(e, f) << "\n" << std::endl;
	std::cout << ::min(g, h) << "\n" << std::endl;

	return 0;
}
