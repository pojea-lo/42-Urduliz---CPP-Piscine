#include "Brain.hpp"

//constructors & destructor
Brain::Brain () {

	std::cout << "Empty Brain constructor was called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "I want to eat " + std::to_string(i) + " bowls of food!!";
	return;
}

Brain::Brain (std::string _ideas[100]) {

	std::cout << "Parameter Brain constructor was called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = _ideas[i];
	return;
}

Brain::Brain (const Brain &obj) {

	std::cout << "Copy Brain constructor was called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return;
}

Brain::~Brain () {

	std::cout << "Brain destructor was called" << std::endl;
	return;
}

//getters & setters
const std::string	*Brain::getIdeas() const {

	return (this->ideas);
}

void	Brain::setIdeas(std::string *_ideas) {

	for (int i = 0; i < 100; i++)
		ideas[i] = _ideas[i];
	return;
}

//overload operators
Brain	&Brain::operator= (const Brain &obj) {

	std::cout << "Overload Brain operator = was called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return (*this);
}

//methodes
void	Brain::printBrains () const {

//	for (int i = 0; i < 100; i++)
	for (int i = 0; i < 5; i++)
		std::cout << this->ideas[i] << std::endl;

	return;
}

void	Brain::printPtrBrain () const {

	std::cout << &ideas[0] << std::endl;
	return;
}
