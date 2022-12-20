#include "CharType.hpp"

//constructors & destructors
CharType::CharType () : n(0) , tmp_str("") {

	std::cout << "Emty CharType constructor was called" << std::endl;
	return;
}

CharType::CharType (const CharType &obj) {

	std::cout << "Copy CharType constructor was called" << std::endl;
	n = obj.n;
	tmp_str = obj.tmp_str;
	return;
}

CharType::~CharType () {

	std::cout << "CharType destructor was called" << std::endl;
	return;
}

//overload operator
CharType	&CharType::operator= (const CharType &obj) {

	std::cout << "Operator CharType = was called" << std::endl;
	n = obj.n;
	tmp_str = obj.tmp_str;
	return *this;
}

//methods
std::string		CharType::check (const std::string &str) {

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

int		CharType::count (const std::string &str) {

	n = 0;
	size_t	i = -1;
	size_t 	j = 0;

	while (++i < str.length() && j == 0) {

		if (str[i] == '.') 
			j = i;
	}

	while (i < str.length()) {

		if (str[i] < 47 || str[i] > 58) {
			return (n);
		}		
		n++;
		i++;
	}

	if (j != 0)
		return (static_cast<int> (str.length() - (j + 1)));
	else
		return (1);
}
