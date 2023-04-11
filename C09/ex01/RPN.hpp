#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class  RPN{

    private:
        std::stack<int>     list;
    
    public:
        RPN();
        RPN(const std::string &str);
        RPN(const RPN &obj);
        ~RPN();

        RPN operator=(const RPN &obj);
        
};

std::stack  ft_create(std::string &str);

#endif