#include "ClapTrap.hpp"

int main() {

	std::string response;

	std::cout << "Please, what's your name??: ";
	std::cin >> response;
	ClapTrap    me(response);
	std::cout << "And what's the name of your oponent??: ";
	std::cin >> response;
	ClapTrap	you(response);	

//	ClapTrap	me("pyoyoso");
//	ClapTrap	you("Lulu");

	std::cout << "\nAt the begining*******************************\n";
	me.printClap();
	you.printClap();
	
	me.takeDamage(6);//recibe fuerza
	you.beRepaired(4);//recibe vida extra
	std::cout << "\nAfter charging damage and extra power*********\n";
	me.printClap();
	you.printClap();
	
	me.attack(you.getName());//ataque 1
	you.chHitpoints(me);//quitado de vida
	std::cout << "\nAnd, after the attack*************************\n";
	if (you.getHitpoints() == 0) 
		ft_lifeComp(&you);//comprobacion de vida
	me.printClap();
	you.printClap();

	me.attack(you.getName());//ataque 2
	you.chHitpoints(me);//quitado de vida
	std::cout << "\nAnd, after the attack*************************\n";
	if (you.getHitpoints() == 0) 
		ft_lifeComp(&you);//comprobacion de vida
	me.printClap();
	you.printClap();

	return 0;
}

ClapTrap	ft_lifeComp (ClapTrap *obj) {
	
	std::cout << "\n" << obj->getName() << " has recharged life with " << obj->getEnergyPoints() << " points*********\n";
	obj->setHitpoints(obj->getHitpoints() + obj->getEnergyPoints()); 

	return *obj;
}
