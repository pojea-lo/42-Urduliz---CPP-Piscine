#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <class T>

class Array {

	private:
		T	*Vec;
		size_t	size;

	public:
		Array() : size(0) {

			std::cout << "Empty constructor was called" << std::endl;
			Vec = new T();

			std::cout << "Valor de empty:                  " << Vec[0] << std::endl;
			std::cout << "Dir. memoria empty:              " << &Vec[0] << std::endl;
			
			return;
		}

		Array(unsigned int n) : size(n) {

			std::cout << "Parameter constructor was called" << std::endl;
			Vec = new T[n]();

			std::cout << "Valor de parameter:              " << Vec[0] << std::endl;
			std::cout << "Dir. memoria parameter:          " << &Vec[0] << std::endl;
			
			return;
		}

		Array(const Array &obj) {
			*this = obj;

			std::cout << "Copy constructor was called" << std::endl;

			std::cout << "Valor de copy:                   " << Vec[0] << std::endl;
			std::cout << "Dir. memoria copy:               " << &Vec[0] << std::endl;
			
			return;
		}

		Array	&operator=(const Array &obj) {
			if (!obj.getSize())
				this->Vec = new T();
			else
			{
				this->Vec = new T[obj.getSize()]();
				for (size_t i = 0; i < obj.getSize(); i++)
					this->Vec[i] = obj.Vec[i];
			}

			std::cout << "Operator = was called" << std::endl;

			std::cout << "Valor de copy:                   " << Vec[0] << std::endl;
			std::cout << "Dir. memoria copy:               " << &Vec[0] << std::endl;
			
			return *this;
		}

		T	&operator[](int n) { 
			if (n < 0 || n > static_cast<int>(this->getSize()))
				throw	std::out_of_range("Out of range");
			std::cout << "Operator [] was called" << std::endl;

			return Vec[n];
		}
		size_t	getSize() const {
			return (this->size);
		}




};

#endif
