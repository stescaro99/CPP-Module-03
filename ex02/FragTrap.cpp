#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), isGuardGate(false)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src.name), isGuardGate(src.isGuardGate)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	if (this->isGuardGate)
	{
		std::cout << "FragTrap " << this->name << " is no more in Gate keeper mode!" << std::endl;
		this->isGuardGate = false;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is out of energy and cannot be repaired!" << std::endl;
		return ;
	}
	if (this->hitPoints == 100)
	{
		std::cout << "FragTrap " << this->name << " has already 100 hit points, it doesn't require any repairs" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " is being repaired, gaining " << amount << " hit points!" << std::endl;
	this->energyPoints -= 1;
	if (this->hitPoints + amount > 100)
		this->hitPoints = 100;
	else
		this->hitPoints += amount;
}

void FragTrap::takeDamage(unsigned int amount)
{
	bool dead = false;

	if (this->isGuardGate)
	{
		std::cout << "FragTrap " << this->name << " is in Gate keeper mode, it cannot take damage!" << std::endl;
		this->energyPoints += 1;
		return ;
	}
	if (this->hitPoints <= amount)
		dead = true;
	std::cout << "FragTrap " << this->name << " is being attacked, losing " << amount << " hit points!" << std::endl;
	this->hitPoints -= amount;
	if (dead)
	{
		std::cout << "FragTrap " << this->name << " is being killed!" << std::endl << "GAME OVER" << std::endl;
		throw std::runtime_error("FragTrap has been killed");
	}
}

void FragTrap::guardGate()
{
	if (this->isGuardGate)
	{
		std::cout << "FragTrap " << this->name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
	this->isGuardGate = true;
}

void FragTrap::highFivesGuys(void)
{
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name << " is out of energy and cannot give high fives!" << std::endl;
		return ;
	}
	if (this->isGuardGate)
	{
		std::cout << "FragTrap " << this->name << " is no more in Gate keeper mode!" << std::endl;
		this->isGuardGate = false;
	}
	std::cout << "FragTrap " << this->name << " gives high fives to everyone!" << std::endl;
	this->energyPoints -= 1;
}