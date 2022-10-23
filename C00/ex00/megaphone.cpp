#include <iostream>

class StrUpper{
	private:
		char	*str;
		int		id;
		int		size;

	public:
		StrUpper(char *, int, int);
		~StrUpper( void );
		void	print_upper(); 
};

//constructor
StrUpper::StrUpper(char *str, int id, int size) {
	this->str = str;
	this->id = id;
	this->size = size;

	return;
}

//destructor
StrUpper::~StrUpper( void ) {

	return;
}

//method
void StrUpper::print_upper(){
	int	i;

	i = -1;
	while (++i < this->size)
		this->str[i] = toupper(this->str[i]);
	if (this->id == 1)
		std::cout << this->str;
	else
		std::cout << " " << this->str;
}

//principal
int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		i = 0;
		while (++i < argc) {
			j = 0;
			while (argv[i][j])
				j++;
			StrUpper actual (argv[i], i, j);
			actual.print_upper();
		}
	}
	std::cout << std::endl;
	return (0);
}
