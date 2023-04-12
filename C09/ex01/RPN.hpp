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
		std::stack<int>     list;
	
	public:
		RPN();
		RPN(char *str);
		RPN(const RPN &obj);
		~RPN();

		RPN &operator=(const RPN &obj);

		void			ft_print();
		std::stack<int>	ft_create(char *str);
		int				ft_operate(char aux);

};

bool			ft_check(char *str);

#endif
