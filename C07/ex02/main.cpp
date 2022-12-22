#include "Array.hpp"

int		main() {

	Array<int>	test;
	Array<int>	test1(12);
	Array<int>	test2(test);
	Array<int>	test3;

	std::cout << "\nEn el main_______________________\n" << std::endl;
	std::cout << "Con empty                        " << &test << std::endl;
	std::cout << "Con parameter                    " << &test1 << std::endl;
	std::cout << "Con copy                         " << &test2 << std::endl;
	test3 = test;
	std::cout << "Con =                            " << &test3 << std::endl;
	try {
		int n = test1[-1];
		std::cout << n << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
