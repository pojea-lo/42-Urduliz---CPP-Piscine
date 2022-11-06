#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen {

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Karen(void);
		~Karen(void);

		void	complain(std::string level);
};

#endif
