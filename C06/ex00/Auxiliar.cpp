#include "Auxiliar.hpp"

//constructors & destructors
Auxiliar::Auxiliar () : n(0) , tmp_str("") {

	std::cout << "Emty Auxiliar constructor was called" << std::endl;
	return;
}

Auxiliar::Auxiliar (const Auxiliar &obj) {

	std::cout << "Copy Auxiliar constructor was called" << std::endl;
	n = obj.n;
	tmp_str = obj.tmp_str;
	return;
}

Auxiliar::~Auxiliar () {

	std::cout << "Auxiliar destructor was called" << std::endl;
	return;
}

//overload operator
Auxiliar	&Auxiliar::operator= (const Auxiliar &obj) {

	std::cout << "Operator Auxiliar = was called" << std::endl;
	n = obj.n;
	tmp_str = obj.tmp_str;
	return *this;
}

//methods
std::string		Auxiliar::check (const std::string &str) {

	try {
//caso de que sea solo 1 bit la cadena y no sea numero, por lo que lo ha de devolver tal cual
		if (str.length() == 1 && (str[0] < 48 || str[0] > 57))
			return ("one");
//caso de que tenga varios bits la cadena
		else {
//en caso de que falle el stoi, salgo por la excepcion
			n = stoi(str);
//case de que tenga números, pero no esté comprendido en los imprimibles
			if (((n >= 0 && n < 32) || (n > 126 && n < 256)))
				return ("Non displayable");
			else if (n < 0 || n > 255)
				return ("impossible");
		}
	}
	catch (std::exception &ex) {
		return ("impossible");
	}

//devuelvo el imprimible
	return ("ok");
}

int		Auxiliar::count (const std::string &str) {

	n = 0;
	size_t	i = -1;
	size_t 	j = 0;

	while (++i < str.length() && j == 0) {

		if (str[i] == '.') 
			j = i;
		else if ((str[i] < 47 || str[i] > 58) && str[i] != '-' && str[i] != '+')
			j = 1000;
	}

	while (i < str.length() && j != 1000) {

		std::cout << "La i: " << i << " - " << str[i] << std::endl;
		if (str[i] < 47 || str[i] > 58) {
			break;
		}		
		n++;
		i++;
	}
	
	std::cout << "La j: " << j << std::endl;

	if (j != 0 && j != 1000) {
		n = static_cast<int> (i - (j + 1));
		std::cout << "La n: " << n << std::endl;
		if (n == 0)
			return (1);
		return n;
	}
	else
		return (1);
}
