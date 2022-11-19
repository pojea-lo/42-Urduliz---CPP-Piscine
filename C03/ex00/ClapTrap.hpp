#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

    private:
        std::string const   Name;
        unsigned int        Hitpoints;
        unsigned int        EnergyPoints;
        unsigned int        AttackDamage;
    
    public:
        ClapTrap ();
        ~ClapTrap ();
        ClapTrap (const ClapTrap &obj);

        ClapTrap &operator= (const ClapTrap &obj);

        std::string getName() const;
        void        setName(std::string str);

        void    attack (std::string const &target);
        void    takeDamage (unsigned int amount);
        void    beRepaired (unsigned int amount);

};

#endif