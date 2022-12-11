#include "DiamondTrap.hpp"

int main() {

	ScravTrap	three ("Three");
	three.printClap();
	FlagTrap	four ("Four");
	four.printClap();
	
	DiamondTrap	one;
	one.printClap();
	DiamondTrap	two("Stich");
	two.printClap();
	DiamondTrap five(one);
	five.printClap();
	five = two;
	five.printClap();

	two.attack("Lilo");
	two.guardGate();
	two.highFiveGuys();
	two.whoAmI();
	std::cout << std::endl;

	return 0;
}
