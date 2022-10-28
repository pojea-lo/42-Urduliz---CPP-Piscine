#include <iostream>

int	main(void) {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "La dirección de memoria:\nPor la string:  " << &str << std::endl;
	std::cout << "Por puntero:    " << stringPTR << std::endl;
	std::cout << "Por referencia: " << &stringREF << std::endl;

	std::cout << "La string:\nPor la string:  " << str << std::endl;
	std::cout << "Por puntero:    " << *stringPTR << std::endl;
	std::cout << "Por referencia: " << stringREF << std::endl;

	return 0;
}
