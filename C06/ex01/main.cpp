#include <iostream>

struct Data {

	int			n = 41;
	float		f = 42.01f;
	char		c = 'l';
	std::string	str = "stich";

	uintptr_t	buf[5];
	
};

uintptr_t	serialize(Data *ptr);
Data 		*deserialize(uintptr_t raw);

int	main() {

		Data	test;

		std::cout << "Partimos de unos valores___________________________________\n" << std::endl;
		std::cout << " *El int:                         " << test.n << std::endl;  
		std::cout << " *El float:                       " << test.f << std::endl;           
		std::cout << " *El char:                        " << test.c << std::endl;           
		std::cout << " *La string:                      " << test.str << std::endl;         

		std::cout << "\nPartimos de unas direcciones de memoria____________________\n" << std::endl;
		std::cout << " *El int:                         " << &test.n << std::endl;           
		std::cout << " *El float:                       " << &test.f << std::endl;           
		std::cout << " *El char:                        " << static_cast<void *>(&test.c) << std::endl;           
		std::cout << " *La string:                      " << &test.str << std::endl;           
		std::cout << " *La estructura Data:             " << &test << std::endl;           

		std::cout << "\nAl aplicarle el serialize__________________________________\n" << std::endl;
		uintptr_t tmp = serialize(&test);
		std::cout << " *El uintptr de la estructura:    " << tmp << std::endl;

		Data new_test;
		std::cout << "Partimos de unos valores de New Test_________________________\n" << std::endl;
		std::cout << " *El int:                         " << new_test.n << std::endl;  
		std::cout << " *El float:                       " << new_test.f << std::endl;           
		std::cout << " *El char:                        " << new_test.c << std::endl;           
		std::cout << " *La string:                      " << new_test.str << std::endl;         
		std::cout << " *La dirección de mem. de New Test:     " << &new_test << std::endl;

		std::cout << "Le cambiamos los valores a New Test_________________________\n" << std::endl;
		new_test.n = 51;
		new_test.f = 52.01f;
		new_test.c = 'o';
		new_test.str = "lilo";
		std::cout << " *El int:                         " << new_test.n << std::endl;  
		std::cout << " *El float:                       " << new_test.f << std::endl;           
		std::cout << " *El char:                        " << new_test.c << std::endl;           
		std::cout << " *La string:                      " << new_test.str << std::endl;         
		std::cout << " *La dirección de mem. de New Test:     " << &new_test << std::endl;

		new_test = *deserialize(tmp);
		std::cout << "\nAl aplicarle el deserialize a New Test, los valores son___\n" << std::endl;
		std::cout << " *El int:                         " << new_test.n << std::endl;  
		std::cout << " *El float:                       " << new_test.f << std::endl;           
		std::cout << " *El char:                        " << new_test.c << std::endl;           
		std::cout << " *La string:                      " << new_test.str << std::endl;         
		std::cout << " *La dirección de mem. de New Test:     " << &new_test << std::endl;
	
	return 0;
}


uintptr_t	serialize(Data *ptr) {

	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);

	void	*ptr1 = &ptr->n;
		ptr->buf[0] = reinterpret_cast<uintptr_t>(ptr1);
		std::cout << " *El uintptr de int:              " << ptr->buf[0] << std::endl;
	ptr1 = &ptr->f;
		ptr->buf[1] = reinterpret_cast<uintptr_t>(ptr1);
		std::cout << " *El uintptr de float:            " << ptr->buf[1] << std::endl;
	ptr1 = &ptr->c;
		ptr->buf[2] = reinterpret_cast<uintptr_t>(ptr1);
		std::cout << " *El uintptr de char:             " << ptr->buf[2] << std::endl;
	ptr1 = &ptr->str;
		ptr->buf[4] = reinterpret_cast<uintptr_t>(ptr1);
		std::cout << " *El uintptr de string:           " << ptr->buf[4] << std::endl;
	return (ret);
}

Data		*deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data *>(raw));
}


