#include "CharType.hpp"

//constructors & destructors
CharType::CharType () : len(0) {

	std::cout << "Emty CharType constructor was called" << std::endl;
	return;
}

CharType::CharType (const CharType &obj) {

	std::cout << "Copy CharType constructor was called" << std::endl;
	len = obj.len;
	return;
}

CharType::~CharType () {

	std::cout << "CharType destructor was called" << std::endl;
	return;
}

//overload operator
CharType	&CharType::operator= (const CharType &obj) {

	std::cout << "Operator CharType = was called" << std::endl;
	len = obj.len;
	return *this;
}

//methods
char	CharType::convert (const std::string &str) {

	if (check(str) == 0) {

		std::cout << "convertimos" << std::endl;

	}

//	else

	return ('a');
}

bool	CharType::check (const std::string &str) {

	size_t		i = -1;

	while (++i < str.length()) {
		if (!(str[i] > 47 && str[i] < 58) && i > 0 && str[i] != '.' && str[i] != 'f') {
			std::cout << "too many bits" << std::endl;
			throw BadArguments();
			return false;
		}
	}
//		for (size_t i = 1; i < str.length(); i++) {
	return true;
}
