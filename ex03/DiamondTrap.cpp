#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	this->isGuardGate = false;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src.name), FragTrap(src.name), ScavTrap(src.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->isGuardGate = rhs.isGuardGate;
		this->name = rhs.name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	this->FragTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "DiamondTrap " << this->name << " is out of energy and cannot be repaired!" << std::endl;
		return ;
	}
	if (this->hitPoints == 100)
	{
		std::cout << "DiamondTrap " << this->name << " has already 100 hit points, it doesn't require any repairs" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->name << " is being repaired, gaining " << amount << " hit points!" << std::endl;
	this->energyPoints -= 1;
	if (this->hitPoints + amount > 100)
		this->hitPoints = 100;
	else
		this->hitPoints += amount;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	bool dead = false;

	if (this->isGuardGate)
	{
		std::cout << "DiamondTrap " << this->name << " is in Gate keeper mode, it cannot take damage!" << std::endl;
		this->energyPoints += 1;
		return ;
	}
	if (this->hitPoints <= amount)
		dead = true;
	std::cout << "DiamondTrap " << this->name << " is being attacked, losing " << amount << " hit points!" << std::endl;
	this->hitPoints -= amount;
	if (dead)
	{
		std::cout << "DiamondTrap " << this->name << " is being killed!" << std::endl << "GAME OVER" << std::endl;
		throw std::runtime_error("DiamondTrap has been killed");
	}
}

void DiamondTrap::guardGate()
{
	if (this->isGuardGate)
	{
		std::cout << "DiamondTrap " << this->name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
	this->isGuardGate = true;
}

void DiamondTrap::highFivesGuys(void)
{
	if (this->energyPoints == 0)
	{
		std::cout << "DiamondTrap " << this->name << " is out of energy and cannot give high fives!" << std::endl;
		return ;
	}
	if (this->isGuardGate)
	{
		std::cout << "DiamondTrap " << this->name << " is no more in Gate keeper mode!" << std::endl;
		this->isGuardGate = false;
	}
	std::cout << "DiamondTrap " << this->name << " gives high fives to everyone!" << std::endl;
	this->energyPoints -= 1;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
}