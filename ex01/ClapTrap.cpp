/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:56:24 by root              #+#    #+#             */
/*   Updated: 2025/09/15 16:57:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//------------------------CONSTRUCTORS                  ------------------------

/**
 * @brief	Default constructor.
 * 			Initializes a ClapTrap with default values for _name, _hitPoints, 
 * 			_energyPoints and _attackDamage.
 * 
 */

ClapTrap::ClapTrap(void) :	_name("default"),
							_hitPoints(10),
							_energyPoints(10),
							_attackDamage(0)	
{
	std::cout << GREEN << "ClapTrap Default constructor called." 
				<< RESET << std::endl;
}

/**
 * @brief	Name constructor.
 * 			Initializates a ClapTrap with the given name and the default
 * 			values for the other attributes.
 * 
 * @param name	The name to assign to this ClapTrap.
 */

ClapTrap::ClapTrap(std::string name) :	_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0)
{
	this->_name = name;
	std::cout << GREEN << "ClaTrap Constructor called for the name " 
				<< name << "." << RESET << std::endl;
}

/**
 * @brief	Copy constructor.
 * 			Creates a new ClapTrap as a copy of another.
 * 
 * @param other	The ClapTrap instance to copy.
 */

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << GREEN << "ClapTrap Copy constructor called for the name " 
				<< other._name << "." << RESET << std::endl;
	*this = other;
}

//------------------------DESTRUCTOR                    ------------------------

/**
 * @brief	Destructor.
 * 			Automatically called when the object goes out of scope.
 * 
 */

ClapTrap::~ClapTrap(void)
{
	std::cout << GREEN << "ClapTrap Destructor called for the name " 
				<< this->_name << RESET << std::endl;	
}

//------------------------OPERATORS                     ------------------------

/**
 * @brief	Copy assignment operator.
 * 			Replaces this ClapTrap with a copy of another.
 * 
 * @param other	The ClapTrap instance to copy from
 * @return Reference to this updated ClapTrap.
 */

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << GREEN << "ClapTrap Assignation operator called." 
				<< RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);	
}

//------------------------PUBLIC METHODS                ------------------------

/**
 * @brief	Performs an attack on the specified target
 * 			- If ClapTrap has at least 1 enery points and positive hit points, 
 * 			it attacks the target, consumes 1 energy point, and displays 
 * 			a message.
 * 			- If if lacks energy or hit points, it cannot atack.
 * 
 * @param target	The name of the target to attack.
 */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name 
				<< " attacks " << target 
				<< ", causing " << this->_attackDamage 
				<< " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name 
					<< " is not able to attack " << target
					<< " because has no energy points left." 
					<< RESET << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << this->_name 
					<< " is not able to attack " << target
					<< " because has no hit points left." 
					<< RESET << std::endl;
	}
}

/**
 * @brief	Reduces the ClapTrap's hit points when taking damage.
 * 			- Substracts the given amount from hit points and displays the new
 * 			status. 
 * 			- If hit points fall to 0 or bellow, the ClapTrap is considered dead.
 * 			
 * @param amount	The amount of damage taken.
 */

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << MAGENTA <<"ClapTrap " << this->_name
					<< " was attacked and lost " << amount 
					<< " hit points. Now, it has " << this->_hitPoints 
					<< " hit points left." << RESET << std::endl;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << this->_name 
					<< " is already dead." << RESET << std::endl;
	}	
}

/**
 * @brief	Repairs the ClapTrap, restoring hit points.
 * 			- If the ClapTrap has at least 1 energy point and positive hit points,
 * 			it gains the specified amount of hit points and consumes 1 energy
 * 			point
 * 			- If it has no energy or is already dead, the repair fails.
 *
 * @param amount	The number of hit points to restore. 
 */

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << CYAN << "ClapTrap " << this->_name	
					<< " repaired itself and gained " << amount
					<< " extra hit points. Now, it has " << this->_hitPoints
					<< " hit points." << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name
					<< " cannot repair itself, because doesn't have enough energy points." 
					<< RESET << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << this->_name
					<< " cannot repair itself, because doesn't have enough hit points." 
					<< RESET << std::endl;
	}
	
}
