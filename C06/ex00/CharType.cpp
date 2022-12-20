#include "CharType.hpp"

//constructors & destructors
CharType::CharType (const std::string &str) : len((int)str.length()) {

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

//getters & setters
int		CharType::getLen() const {

	return len;
}

//methods
char	*CharType::convert (std::string &str) {

	int	n = 0;
		
	try {
		if (len == 1)
			return (static_cast<char *> ("Displayable"));
//			return (str.c_str());
		else {
			n = stoi(str);
			if ((n >= 0 && n < 32) || (n > 126 && n < 256))
				return (static_cast<char *> ("Non displayable"));
		}
	}

	catch (std::exception &ex) {
		return (static_cast<char *> ("impossible"));
		std::cout << ex.what() << std::endl;
	}


	return ("a");
}
/*
bool	CharType::check (const std::string &str) {

	int		i = -1;

	std::cout << str << std::endl;
	while (++i < len) {
		if ((str[i] < 48 || str[i] > 57) && ft_character(str[i]) == 0 && i > 0) {
			throw BadArguments();
			return false;
		}
	}
//		for (size_t i = 1; i < str.length(); i++) {
	return true;
}*/