#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

class  RPN {

	private:
		std::stack<int>     list;
	
	public:
		RPN();
		RPN(int argc, char **str);
		RPN(const RPN &obj);
		~RPN();

		RPN &operator=(const RPN &obj);
		
};

bool			ft_check(int argc, char **str);
std::stack<int>	ft_create(const std::string &str);

#endif