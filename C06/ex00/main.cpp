#include "exception.hpp"
#include "CharType.hpp"

int	main(int argc, char *argv[]) {

	char			char_ex;
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
		
		CharType	one;
		char_ex = one.convert (argument);





			std::cout << "\'" << static_cast<char> (42.0f) << "\'" << std::endl;
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

	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
