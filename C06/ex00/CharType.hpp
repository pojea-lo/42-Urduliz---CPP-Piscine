#ifndef CHARTYPE_HPP
# define CHARTYPE_HPP

#include "exception.hpp"

class CharType {

	private:
		int		len;

	public:

		CharType();
		CharType(const CharType &obj);
		~CharType();

		CharType	&operator= (const CharType &obj);

		char	convert(const std::string &str);
		bool	check(const std::string &str);

		class		BadArguments : public std::exception {

			public:
				const char *what() const throw() {
					return ("Bad arguments to Char cast\n");
				}
		};


};

#endif
