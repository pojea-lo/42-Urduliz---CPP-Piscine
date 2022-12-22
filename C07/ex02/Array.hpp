#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include "Fixed.hpp"

template <class T>

class Array {

	private:
		T	*Vec;
		size_t	size;

	public:

//constructors & destructors
		Array() : size(0) {

			std::cout << "Empty constructor was called" << std::endl;
			Vec = new T();

			return;
		}

		Array(unsigned int n) : size(n) {
			
			if (n < 0)
				throw	std::out_of_range("Out of range");

			std::cout << "Parameter constructor was called" << std::endl;
			Vec = new T[n]();
			for (size_t i = 0; i < static_cast<size_t>(n); i++)
//				Vec[i] = i;//para int
				Vec[i] = 50.02f + static_cast<float>(i);//para fixed

			return;
		}

		Array(const Array &obj) {

			std::cout << "Copy constructor was called" << std::endl;
			*this = obj;

			return;
		}

//overload operators
		Array	&operator=(const Array &obj) {
	
			std::cout << "Operator = was called" << std::endl;

			if (!obj.getSize())
				Vec = new T();
			else
			{
				Vec = new T[obj.getSize()]();
				for (size_t i = 0; i < obj.getSize(); i++)
					Vec[i] = obj.Vec[i];
			}
			size = obj.size;

			return *this;
		}

		T	&operator[](int n) { 
			
			if (n < 0 || n > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
			
			return Vec[n];
		}

//getters & setters
		size_t	getSize() const {
			
			return (this->size);
		}

		T	getVec(int pos) const {

			if (pos < 0 || pos > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
		
			return (Vec[pos]);
		}

		void	setVec(T neu, int pos) {

			if (pos < 0 || pos > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
			
			Vec[pos] = neu;

			return;
		}
};

#endif
