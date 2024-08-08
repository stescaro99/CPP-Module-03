#include "ClapTrap.hpp"

int main(void)
{
	try
	{
		ClapTrap ct1("Putin");
		ClapTrap ct1cp(ct1);
		ClapTrap ct2("");
		ct2 = ct1;

		ct1.attack("Ukraine");
		ct1.takeDamage(2);
		ct1.beRepaired(5);
		ct1.beRepaired(10);
		for (int i=0; i < 9; i++)
			ct1.attack("Ukraine");
		ct1.takeDamage(10);
		ct1.beRepaired(10);
	}
	catch (const std::runtime_error& e)
	{
        return 0;
	}
	return 0;
}