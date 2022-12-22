#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class myType>

void	iter(myType *obj, size_t n, void f(const myType &)) {

	for (size_t i = 0; i < n; i++)
		f(obj[i]);

	return;
}

template <class myType>

void	print(const myType &obj) {

	std::cout << obj << "  ";
	return;
}

template <class myType>

myType	add_42(myType obj) {

	return (obj + 42);
}

#endif
