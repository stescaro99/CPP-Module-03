#include "DiamondTrap.hpp"

int main(void)
{
	try
	{
		DiamondTrap dt1("Putin");
		DiamondTrap dt1cp(dt1);
		DiamondTrap dt2("");
		dt2 = dt1;
		dt1.attack("Ukraine");
		dt1.takeDamage(2);
		dt1.beRepaired(5);
		dt1.takeDamage(10);
		dt1.guardGate();
		dt1.takeDamage(100);
		dt1.guardGate();
		dt1.beRepaired(140);
		dt1.attack("Ukraine");
		dt1.highFivesGuys();
		dt1.guardGate();
		dt1.whoAmI();
		dt1.takeDamage(100);
	}
	catch (const std::runtime_error& e)
	{
        return 0;
	}
	
	return 0;
}