#include "Array.hpp"

int		main() {

	std::cout << "\nEmpty constructor_______________________\n" << std::endl;
	
	Array<int>	test;
//	Array<Fixed>	test;
	std::cout << "Con empty: &Test                 " << &test << std::endl;
	
	std::cout << "\nParameter constructor___________________\n" << std::endl;

	Array<int>	test1(12);
//	Array<Fixed>	test1(7);
	std::cout << "Con parameter: &Test1            " << &test1 << std::endl;

	std::cout << "\nCopy constructor________________________\n" << std::endl;

	Array<int>	test2(test);
//	Array<Fixed>	test2(test);
	std::cout << "Con copy: &Test2                 " << &test2 << std::endl;
	
	std::cout << "\nOperator =______________________________\n" << std::endl;

	Array<int>	test3;
//	Array<Fixed>	test3;
	test3 = test1;
	std::cout << "Con =: &Test1                    " << &test1 << std::endl;
	std::cout << "Con =: &Test3                    " << &test3 << std::endl;

	std::cout << "Test 1: ";
	for (size_t i = 0; i < test1.getSize(); i++)
		std::cout << test1.getVec(i) << "  ";
	std::cout << std::endl;
	std::cout << "Test 3: ";
	for (size_t i = 0; i < test3.getSize(); i++)
		std::cout << test3.getVec(i) << "  ";

	std::cout << std::endl;
	
	std::cout << "\nDeep copy comprobations ________________\n" << std::endl;

	std::cout << "Before the change:\nPos 3 of test 1: " << test1.getVec(3) << std::endl;
	std::cout << "Pos 3 of test 3: "<< test3.getVec(3) << std::endl;
	
	test1.setVec(0, 3);
	
	std::cout << "\nAfter the change:\nPos 3 of test 1: " << test1.getVec(3) << std::endl;
	std::cout << "Pos 3 of test 3: "<< test3.getVec(3) << std::endl;

	std::cout << "\nOperator []_____________________________\n" << std::endl;

	std::cout << "Con pos = -1:   ";
	try {
		std::cout << test1[-1] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Con pos = 2:    ";
	try {
		std::cout << test1[2] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Con pos = 15:   ";
	try {
		std::cout << test1[15] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nSize ___________________________________\n" << std::endl;

	std::cout << "Test tiene un size de " << test.getSize() << std::endl;
	std::cout << "Test 1 tiene un size de " << test1.getSize() << std::endl;
	std::cout << "Test 3 tiene un size de " << test3.getSize() << std::endl;

	return 0;
}
