#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain {

	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(std::string _ideas[100]);
		Brain(const Brain &obj);
		~Brain();

		Brain	&operator=(const Brain &obj);

		const std::string	*getIdeas() const;
		void				setIdeas(std::string _ideas[100]);

		void	printBrains () const;

};

#endif
