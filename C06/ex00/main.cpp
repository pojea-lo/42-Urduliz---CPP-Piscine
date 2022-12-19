#include "exception.hpp"

int	main(int argc, char *argv[]) {

	char			char_ex;
	int				int_ex;
	float			flo_ex;
	double			doub_ex;
	std::string		argument;

	try {

		if (argc != 2) {
			throw 1;
			return -1;
		}
		argument = static_cast<std::string> (argv[1]);
		for (size_t i = 0; i < argument.length(); i++) {

			if (argument[i] 






			char_ex = static_cast<char> (65);
			std::cout << char_ex << std::endl;
			int_ex = static_cast<int> ('a');
			std::cout << int_ex << std::endl;
			flo_ex = static_cast<float> (2.5);
			std::cout << flo_ex << std::endl;
			doub_ex = static_cast<double> (2.5);
			std::cout << doub_ex << std::endl;



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
