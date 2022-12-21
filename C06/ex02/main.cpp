#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <typeinfo>

Base	*generate(void);
void	identify(Base *p);

int	main() {

	Base	*one;

	one = generate();
	
	identify (one);

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