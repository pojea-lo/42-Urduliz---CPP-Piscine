#ifndef AUXILIAR_HPP
# define AUXILIAR_HPP

#include <iostream>

class Auxiliar {

	private:
		int			n;
		std::string	tmp_str;

	public:

		Auxiliar();
		Auxiliar(const Auxiliar &obj);
		~Auxiliar();

		Auxiliar	&operator= (const Auxiliar &obj);

		std::string		check(const std::string &str);
		int				count(const std::string &str);

};


#endif
