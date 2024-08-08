#include "ScavTrap.hpp"

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
		st1.takeDamage(100);
	}
	catch (const std::runtime_error& e)
	{
        return 0;
	}
	
	return 0;
}