#include "mutantstack.hpp"

//constructors & destructors
template <typename T>
MutantStack<T>::MutantStack() {

    std::cout << "Empty constructor was called" << std::endl;
    return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &obj) {

    std::cout << "Copy constructor was called" << std::endl;
    *this = obj;    
    return *this;
} 

template <typename T>
MutantStack<T>::~MutantStack() {

    std::cout << "Destructor was called" << std::endl;
    return;
}

//overload operators
template <typename T>
MutantStack<T>     &MutantStack<T>::operator= (const MutantStack &obj) {

    std::cout << "Operator = was called" << std::endl;
    *this = obj;
    return *this;
}

//iterators
template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin() {

    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end() {

    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator    MutantStack<T>::rbegin() {

    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator    MutantStack<T>::rend() {

    return this->c.rend();
}