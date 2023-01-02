#include "iter.hpp"

int	main() {
	
	int		n[] = {0, 1, 2, 3, 4};
	char	c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	Fixed	f[] = {42.4f, 42.42f, 42.424f};

	std::cout << "Array de int_____________\n" << std::endl;
	iter (n, 5, print<int>);
	
	std::cout << "\n\nArray de char____________\n" << std::endl;
	iter (c, 7, print<char>);
	
	std::cout << "\n\nArray de Fixed___________\n" << std::endl;
	iter (f, 3, print<Fixed>);
	std::cout << std::endl;


	return 0;
}
