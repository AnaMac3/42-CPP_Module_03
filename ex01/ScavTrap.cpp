/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:00:25 by root              #+#    #+#             */
/*   Updated: 2025/09/20 12:20:11 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

/**
 * @brief	Default constructor.
 * 			Initializes a ScavTrap object by calling the default constructor
 * 			of ClapTrap. Then sets ScavTrap-specific attribute values and
 * 			displays a debug msg.
 * 
 */

ScavTrap::ScavTrap(void) :	ClapTrap()
{
	_name = "default_scav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << GREEN_CHILD << "ScavTrap Default constructor called."
				<< RESET << std::endl;
}

/**
 * @brief	Name constructor.
 * 			Initializes a ScavTrap object by calling the ClapTrap constructor
 * 			with a name. Then sets ScavTrap-specific attribute values.
 * 			Displays a debug message.
 * 
 * @param name	The name to assign to this ScavTrap.
 */

ScavTrap::ScavTrap(std::string name) :	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << GREEN_CHILD << "ScavTrap Constructor called for the name " 
				<< name << "." << RESET << std::endl;
}

/**
 * @brief	Copy constructor.
 * 			Creates a new ScavTrap object as a copy of another ScavTrap.
 * 			Calls the ClapTrap copy constructor to copy base class atributes.
 * 			Displays a debug message.
 * 
 * @param other	The ScavTrap instance to copy.
 */

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << GREEN_CHILD << "ScavTrap Copy constructor called for the name " 
				<< other._name << "." << RESET << std::endl;
}

/**
 * @brief	Copy assignment operator.
 * 			Replaces this ScavTrap with a copy of another.
 * 			Delegates the copy of ClapTrap attributes to ClapTrap's
 * 			assignment operator
 * 
 * @param other	The ScavTrap instance to copy from
 * @return Reference to this updated ScavTrap.
 */

ScavTrap	&ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << GREEN_CHILD << "ScavTrap Assignation operator called." 
				<< RESET << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);	
}

/**
 * @brief	Destructor.
 * 			Automatically called when the object goes out of scope.
 * 			The base class destructor (ClapTrap::~ClapTrap) us called
 * 			automatically after the derived destructor finishes.
 * 			Displays a debug message.
 * 
 */

ScavTrap::~ScavTrap(void)
{
	std::cout << GREEN_CHILD << "ScavTrap Destructor called for the name " 
				<< this->_name << RESET << std::endl;	
}

//------------------------PUBLIC METHODS                ------------------------

/**
 * @brief	Overrides the attack method from ClapTrap.
 * 			Performs an attack on the specified target
 * 			- If ScavTrap has at least 1 enery points and positive hit points, 
 * 			it attacks the target, consumes 1 energy point, and displays 
 * 			a message.
 * 			- If if lacks energy or hit points, it cannot atack.
 * 
 * @param target	The name of the target to attack.
 */

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << BLUE_CHILD << "ScavTrap " << this->_name 
				<< " attacks " << target 
				<< ", causing " << this->_attackDamage 
				<< " points of damage!" << RESET << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << YELLOW_CHILD << "ScavTrap " << this->_name 
					<< " is not able to attack " << target
					<< " because has no energy points left." 
					<< RESET << std::endl;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << RED_CHILD << "ScavTrap " << this->_name 
					<< " is not able to attack " << target
					<< " because has no hit points left." 
					<< RESET << std::endl;
	}
}

/**
 * @brief	Special ability of ScavTrap: guardGate mode.
 * 			Puts the ScavTrap in "Gate keeper" mode by displaying a message.
 * 			This method is unique to ScavTrap and doesn't exist in ClapTrap.
 * 
 * @param target	The name of the target to attack.
 */

void	ScavTrap::guardGate()
{
	std::cout << BLUE_CHILD << "Scavtrap " << this->_name
				<< " is in Gate keeper mode." << RESET << std::endl;
}
