#include "FragTrap.hpp"

int main(void)
{
	try
	{
		ScavTrap st1("Putin");
		ScavTrap st1cp(st1);
		ScavTrap st2("");
		st2 = st1;
		st1.attack("Ukraine");
		st1.takeDamage(2);
		st1.beRepaired(5);
		st1.takeDamage(10);
		st1.guardGate();
		st1.takeDamage(100);
		st1.guardGate();
		st1.beRepaired(140);
		st1.attack("Ukraine");

		FragTrap ft1("Putin");
		FragTrap ft1cp(ft1);
		FragTrap ft2("");
		ft2 = ft1;
		ft1.attack("Ukraine");
		ft1.takeDamage(2);
		ft1.beRepaired(5);
		ft1.takeDamage(10);
		ft1.guardGate();
		ft1.takeDamage(100);
		ft1.guardGate();
		ft1.highFivesGuys();
		ft1.guardGate();
		ft1.beRepaired(140);
		ft1.attack("Ukraine");
		ft1.highFivesGuys();
		ft1.takeDamage(100);
	}
	catch (const std::runtime_error& e)
	{
        return 0;
	}
	
	return 0;
}