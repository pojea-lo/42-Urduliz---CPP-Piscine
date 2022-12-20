#ifndef CHARTYPE_HPP
# define CHARTYPE_HPP

#include "exception.hpp"

class CharType {

	private:
		int		len;

	public:

		CharType(const std::string &str);
		CharType(const CharType &obj);
		~CharType();

		CharType	&operator= (const CharType &obj);

		int		getLen() const;

		char	*convert(std::string &str);
		bool	check(const std::string &str);

		class		BadArguments : public std::exception {

			public:
				const char *what() const throw() {
					return ("Bad arguments to Char cast\n");
				}
		};


};


#endif
