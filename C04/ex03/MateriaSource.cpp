#include "MateriaSource.hpp"

//constructor & destructor
MateriaSource::MateriaSource () {

	std::cout << "Empty MateriaSource constructor was called" << std::endl;
	for (int i = 0; i < 4; i++)
		book[i] = NULL;
	return;
}

MateriaSource::MateriaSource (const MateriaSource &obj) {

	std::cout << "Copy MateriaSource constructor was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (obj.book[i] != NULL)
			book[i] = obj.book[i]->clone();//deep copy
		else
			book[i] = NULL;
	}
	return;
}

MateriaSource::~MateriaSource () {

	std::cout << "MateriaSource destructor was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (book[i] != NULL)
			delete book[i];
	}
	return;
}

//overload operators
MateriaSource	&MateriaSource::operator= (const MateriaSource &obj) {

	std::cout << "Overload MateriaSource = was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (obj.book[i] != NULL)
			book[i] = obj.book[i]->clone();//deep copy
		else
			book[i] = NULL;
	}
	return *this;
}

//methods
void	MateriaSource::learnMateria (AMateria *_materia) {

	int	i = 0;
	while (i < 4) {
		if (book [i] == NULL) {
			std::cout << _materia->getType() << " was added to your book" << std::endl;
			book[i] = _materia;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "Sorry, but your book are already complete" << std::endl;
	return;
}

AMateria	*MateriaSource::createMateria (std::string const &type) {

	int	i = 0;
	while (i < 4) {
		if (book[i]->getType() == type) {
			std::cout << type << " was clonned" << std::endl;
			return book[i]->clone();
		}
		i++;
	}
	if (i == 4)
		std::cout << "Sorry, but you have not learned this type of Materia, so I can`t create it" << std::endl;
	return 0;
}
