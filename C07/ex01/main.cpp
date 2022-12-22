#include "iter.hpp"
#include "Fixed.hpp"

int	main() {
	
	int		n[] = {0, 1, 2, 3, 4};
	Fixed	f[] = {42.4f, 42.42f, 42.424f};

	iter (n, 5, print<int>);
	iter (f, 3, print<Fixed>);


	return 0;
}
