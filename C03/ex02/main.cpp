#include "ScravTrap.hpp"
#include "FlagTrap.hpp"

int main() {

	std::string response;

	FlagTrap    me;
	std::cout << "\nPlease, what's your FlapTrap name??: ";
	std::cin >> response;
	me.setName(response);

	std::cout << "\nAnd what's the name of your oponent FlagTrap??: ";
	std::cin >> response;
	FlagTrap	you(response);	

	std::cout << "\nAnd the name of your oponent ScravTrap??: ";
	std::cin >> response;
	ScravTrap	he(response);	

	
	std::cout << "\nFlagtrap objects: " << std::endl;
	me.printClap();
	you.printClap();
	me.attack(you.getName());
	me.highFiveGuys();
	you = me;
	you.printClap();
	std::cout << "\nScravtrap objects: " << std::endl;
	he.printClap();
	he.guardGate();

	
	return 0;
}
