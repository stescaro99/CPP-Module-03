#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot be repaired!" << std::endl;
		return ;
	}
	if (this->hitPoints == 10)
	{
		std::cout << "ClapTrap " << this->name << " has already 10 hit points, it doesn't require any repairs" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is being repaired, gaining " << amount << " hit points!" << std::endl;
	this->energyPoints -= 1;
	if (this->hitPoints + amount > 10)
		this->hitPoints =  10;
	else
		this->hitPoints += amount;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	bool dead = false;

	if (this->hitPoints <= amount)
		dead = true;
	std::cout << "ClapTrap " << this->name << " is being attacked, losing " << amount << " hit points!" << std::endl;
	this->hitPoints -= amount;
	if (dead)
	{
		std::cout << "ClapTrap " << this->name << " is being killed!" << std::endl << "GAME OVER" << std::endl;
		throw std::runtime_error("ClapTrap has been killed");;
	}
}