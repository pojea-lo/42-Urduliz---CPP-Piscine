#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include <iostream>

class exception {

	public:
		exception() throw();
		virtual ~exception() throw();
		
		virtual const char* what() const throw();
};
it
#endif
