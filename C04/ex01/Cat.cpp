#include "Cat.hpp"

//constructor & destructor
Cat::Cat() {

	std::cout << "Empty Cat constructor was called" << std::endl;
	setType("Cat");
	cerebro = new Brain();
	return;
}

Cat::Cat (const Cat &obj) {

	std::cout << "Copy Cat constructor was called" << std::endl;
	setType(obj.type);
	cerebro = new Brain();
	*cerebro = *obj.cerebro;
//la opcion abajo marcada no hace deep copy (o eso creo yo). Si la activamos, veos como las direcciones de meoria de ambas ideas 0 del  main (prueba 1 y 2) son la misma, y a la hora de querer borrar la segunda da SEGF porque lógicamente ya estaba eliminada con la primera
//	cerebro = obj.cerebro;

	return;
}

Cat::~Cat () {

	std::cout << "Cat destructor was called" << std::endl;
	delete cerebro;
	return;
}

//overload operators
Cat		&Cat::operator= (const Cat &obj) {

	std::cout << "Overload Cat operator = was called" << std::endl;
	type = obj.type;
	*cerebro = *obj.cerebro;
	return *this;
}

//getters & setters
std::string	Cat::getType() const {

	return (type);
}

void	Cat::setType(std::string _type) {

	type = _type;
	return;
}

Brain	Cat::getIdeas() const {

	return (*cerebro);
}

void	Cat::setIdeas(std::string *_ideas) {

	cerebro->setIdeas(_ideas);
	return;
}

//methods
void	Cat::makeSound() const {

	std::cout << "This class type " << getType() << " makes miau miau!!!" << std::endl;
	return;
}

void	Cat::printCat() const {

	std::cout << "The type is: " << type << std::endl;
	std::cout << "The first 5 ideas are: " << std::endl;
	cerebro->printBrains();
	return;
}

void	Cat::printMemoryCat() const {

	std::cout << "The type of this class is: " << type << std::endl;
	std::cout << ", the pointer of the type of this class is:  " << &type << std::endl;
	std::cout << ", the pointer of the brain of this class is: " << &cerebro << std::endl;
	std::cout << " and the pointer of the idea numbr 0 is:     ";
	cerebro->printPtrBrain ();
	std::cout << std::endl;
	return;
}
