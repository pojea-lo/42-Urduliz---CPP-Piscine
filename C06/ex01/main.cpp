#include <iostream>

//uintptr_t	serialize(Data *ptr);
//Data 		*deserialize(uintptr_t raw);

uintptr_t	serialize(char *ptr);
char 		*deserialize(uintptr_t raw);

int	main() {

	size_t			len = 0;
	int				aux = 0;
	std::string		reponse = "";

//petición de datos al usuario
/*
	std::cout << "What size do you want of structure?: ";
point1:
	try {
		std::cin >> reponse;
		len = std::stoi(reponse);
		if (len >= 65535)
			throw 1;
	}
	catch (std::exception &ex) {
		std::cout << "Please, type only possitive numbers. Try again." << std::endl;
		goto point1;
	}
	catch (int ex) {
		std::cout << "Please, type only possitive numbers. Try again." << std::endl;
		goto point1;
	}
*/
//inicializo las estructuras de datos para trabajar con ellas

/*	int		vector1[len];
	for (size_t i = 0; i < len; i++) {
		*vector1[i] = new int;
		vector1[i] = static_cast<int>(i);
	}
*/
	float	vector2[len];
	for (size_t i = 0; i < len; i++)
		vector2[i] = static_cast<float>(i);

	char	vector3[len];
	for (size_t i = 0; i < len; i++) {
		if ((aux + 65) == 91)
			aux = 0;
		vector3[i] = aux + 65;
		aux++;
	}

	std::string		vector4[len];
	for (size_t i = 0; i < len; i++) {
		std::string	s(1, vector3[i]); 
		vector4[i] = "string " + s;
	}

//inicio los casteos con SEIALIZE
//casteo de int
	
//	for (size_t i = 0; i < len; i++) 

		char	c = 'a';
		char	*pr = &c;

		std::cout << static_cast<void *>(pr) << std::endl;
		std::cout << static_cast<void *>(&c) << std::endl;
		uintptr_t tmp = serialize(pr);
		std::cout << tmp << std::endl;
		std::cout << deserialize(tmp) << std::endl;
	





	return 0;
}


uintptr_t	serialize(char *ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

char			*deserialize(uintptr_t raw) {


	return (reinterpret_cast<char *>(raw));
}


