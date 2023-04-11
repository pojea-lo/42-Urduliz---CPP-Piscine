#include "RPN.hpp"

//canonical various    
RPN::RPN() : list() {

    return;    
}

RPN::RPN(const std::string &str) {

    list = ft_create(str);
    return;
}

RPN::RPN(const RPN &obj) {

    *this = obj;
    return;
}

~RPN() {

    return;
}

RPN operator=(const RPN &obj) {

    this->list = obj->list;
    return *this;    
}

//external functions
std::stack  ft_create(const std::string &str) {



    
}

#endif