#include "ScravTrap.hpp"

int main() {

	std::string response;

	ScravTrap    me;
	std::cout << "Please, what's your name??: ";
	std::cin >> response;
	me.setName(response);

	std::cout << "And what's the name of your oponent??: ";
	std::cin >> response;
	ScravTrap	you(response);	

	me.printClap();
	you.printClap();
	me.guardGate();
	you.guardGate();

	
	return 0;
}
