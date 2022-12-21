#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <typeinfo>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main() {

	Base	*one;
	Base	*two = NULL;

	one = generate();

	
		std::cout << "La clase de one es:           ";
		identify (one);
		identify (*one);
		std::cout << "La clase de two (null) es:    ";
		identify (two);
		identify (*two);
	

	delete one;
	return 0;
}

Base	*generate(void) {

	int		n;
	Base	*obj;

//genero numero aleatorio
	srand(time(NULL));
	n = rand() % 3;
	std::cout << "El número aleatorio es: " << n << std::endl;

	switch (n) {
		case 0:
			obj = new A();
			break;
		case 1:
			obj = new B();
			break;
		default:
			obj = new C();
			break;
	}
	return (obj);
}

void	identify(Base *p) {

	if (!p)
		std::cout << "null" << std::endl;

	A	*a = dynamic_cast<A*> (p);
	if (a)
		std::cout << "A" << std::endl;

	B	*b = dynamic_cast<B*> (p);
	if (b)
		std::cout << "B" << std::endl;
		
	C	*c = dynamic_cast<C*> (p);
	if (c)
		std::cout << "C" << std::endl;
	
	return;
}

void	identify(Base &p) {

	try {
		if (&p == (void *)0x0)
			throw std::bad_cast();
	}
	catch (std::exception &ex) {

		std::cout << "Casted of &null is not possible" << std::endl;
		return;
	}

	try {
		A &a = dynamic_cast<A&> (p);
		(void) a;
		std::cout << "&A" << std::endl;

	}
	catch (std::exception &ex) {

		std::cout << "Casted &A is not possible" << std::endl;
	}
	try {
		B &b = dynamic_cast<B&> (p);
		(void) b;
		std::cout << "&B" << std::endl;

	}
	catch (std::exception &ex) {

		std::cout << "Casted &B is not possible" << std::endl;
	}
	try {
		C &c = dynamic_cast<C&> (p);
		(void) c;
		std::cout << "&C" << std::endl;

	}
	catch (std::exception &ex) {

		std::cout << "Casted &C is not possible" << std::endl;
	}

	return;
}