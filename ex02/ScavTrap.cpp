#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), isGuardGate(false)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.name), isGuardGate(src.isGuardGate)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	if (this->isGuardGate)
	{
		std::cout << "ScavTrap " << this->name << " is no more in Gate keeper mode!" << std::endl;
		this->isGuardGate = false;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy and cannot be repaired!" << std::endl;
		return ;
	}
	if (this->hitPoints == 100)
	{
		std::cout << "ScavTrap " << this->name << " has already 100 hit points, it doesn't require any repairs" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is being repaired, gaining " << amount << " hit points!" << std::endl;
	this->energyPoints -= 1;
	if (this->hitPoints + amount > 100)
		this->hitPoints = 100;
	else
		this->hitPoints += amount;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	bool dead = false;

	if (this->isGuardGate)
	{
		std::cout << "ScavTrap " << this->name << " is in Gate keeper mode, it cannot take damage!" << std::endl;
		this->energyPoints += 1;
		return ;
	}
	if (this->hitPoints <= amount)
		dead = true;
	std::cout << "ScavTrap " << this->name << " is being attacked, losing " << amount << " hit points!" << std::endl;
	this->hitPoints -= amount;
	if (dead)
	{
		std::cout << "ScavTrap " << this->name << " is being killed!" << std::endl << "GAME OVER" << std::endl;
		throw std::runtime_error("ScavTrap has been killed");
	}
}

void ScavTrap::guardGate()
{
	if (this->isGuardGate)
	{
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
	this->isGuardGate = true;
}