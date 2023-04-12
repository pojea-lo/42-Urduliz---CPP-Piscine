#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <sstream>

class  RPN {

	private:
		std::stack<float>     list;
	
	public:
		RPN();
		RPN(char *str);
		RPN(const RPN &obj);
		~RPN();

		RPN &operator=(const RPN &obj);

		void				ft_print();

};

bool				ft_check(char *str);
std::stack<float>	ft_create(char *str);
float				ft_operate(char aux, float sol1, float sol2);

#endif
