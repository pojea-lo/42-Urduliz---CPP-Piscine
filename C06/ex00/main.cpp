#include "exception.hpp"
#include "CharType.hpp"

int	main(int argc, char *argv[]) {

	char			*char_ex;
//	int				int_ex;
//	float			flo_ex;
//	double			doub_ex;
	std::string		argument;

	try {

		if (argc != 2) {
			throw 1;
			return -1;
		}
		argument = static_cast<std::string> (argv[1]);
		
//char cast	
	
		CharType	one(argument);
	
		char_ex = one.convert(argument);

		if (char_ex != 0)
			std::cout << "My char cast:       " << char_ex << std::endl;
		else//guarrada, quitar de aqui!!
			std::cout << "My char cast:       impossible" << std::endl;

		if (one.getLen() == 1)
			std::cout << "Original char cast: " << static_cast<char> (argv[1][0]) << std::endl;
//****ESCRIBIR DENTRO DE LOS PARENTESIS EL ARGUMENTO INTRODUCIDO****
		else {
			std::cout << "Original char cast: " << static_cast<char> (56.0f) << std::endl;
		}



/*			int_ex = static_cast<int> ('a');
			std::cout << int_ex << std::endl;
			flo_ex = static_cast<float> (2.235264525345345636);
			std::cout << flo_ex << std::endl;
			doub_ex = static_cast<double> (2.5);
			std::cout << doub_ex << std::endl;
*/


//		}






	}

	catch (int i) {

		if (i == 1)
			std::cout << "Bad number of arguments" << std::endl;
	}

/*	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
*/
	return 0;
}
