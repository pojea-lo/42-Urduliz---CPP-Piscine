#include "span.hpp"

int	main() {

	std::string		reponse;
	int				n = 0;				
	int				n1 = 0;				

point1:
	std::cout << "Please introduce the size of the vector: ";
	std::cin >> reponse;
	try {
		n = stoi (reponse);
		if (n <= 0)
			throw 1;	
	}
	catch (std::exception &ex) {

		std::cout << "Bad input. Try again!!" << std::endl;
		goto point1;
	}
	catch (int k) {

		std::cout << "Out of range. Try again!!" << std::endl;
		goto point1;
	}

	Span	test(n);

point2:
	std::cout << "Define me now the beggining of the serie: ";
	std::cin >> reponse;
	try {
		n = stoi(reponse);
		if (n <= 0)
			throw 1;
		std::cout << "And the quantity of numbers of the series: ";
		std::cin >> reponse;
		n1 = stoi(reponse);
		if (n1 < 0)
			throw 1;
	}
	catch (std::exception &ex) {

		std::cout << "Bad input. Try again!!" << std::endl;
		goto point2;
	}
	catch (int k) {

		std::cout << "Out of range. Try again!!" << std::endl;
		goto point2;
	}

	try {
		for (int i = 0; i < n1; i++) {
			test.addNumber(((2 * n) - 1) ^ 2);
			n++;
		}
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}

	std::cout << "\nThe vector is: ";
	for (size_t i = 0; i < test.getId(); i++)
		std::cout << test.getTest(i) << "   ";
	std::cout << std::endl;

	try {
		n = test.shortestSpan();
		std::cout << "\nThe shortest span of the serie is: " << n << std::endl;
		
		n = test.longestSpan();
		std::cout << "\nThe longest span of the serie is: " << n << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}

	return 0;

}
