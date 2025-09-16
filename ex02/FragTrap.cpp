/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:18:58 by root              #+#    #+#             */
/*   Updated: 2025/09/16 10:07:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"


//------------------------CONSTRUCTORS                  ------------------------

/**
 * @brief	Default constructor.
 * 			Initializes a FragTrap object by calling the default constructor
 * 			of ClapTrap. Then sets FragTrap-specific attribute values and
 * 			displays a debug msg.
 * 
 */

FragTrap::FragTrap(void) :	ClapTrap()
{
	_name = "default_scav";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << GREEN_CHILD2 << "FragTrap Default constructor called."
				<< RESET << std::endl;
}

/**
 * @brief	Name constructor.
 * 			Initializes a FragTrap object by calling the ClapTrap constructor
 * 			with a name. Then sets FragTrap-specific attribute values.
 * 			Displays a debug message.
 * 
 * @param name	The name to assign to this FragTrap.
 */

FragTrap::FragTrap(std::string name) :	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << GREEN_CHILD2 << "FragTrap Constructor called for the name " 
				<< name << "." << RESET << std::endl;
}

/**
 * @brief	Copy constructor.
 * 			Creates a new FragTrap object as a copy of another FragTrap.
 * 			Calls the ClapTrap copy constructor to copy base class atributes.
 * 			Displays a debug message.
 * 
 * @param other	The FragTrap instance to copy.
 */

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << GREEN_CHILD2 << "FragTrap Copy constructor called for the name " 
				<< other._name << "." << RESET << std::endl;
}


//------------------------DESTRUCTOR                    ------------------------

/**
 * @brief	Destructor.
 * 			Automatically called when the object goes out of scope.
 * 			The base class destructor (ClapTrap::~ClapTrap) us called
 * 			automatically after the derived destructor finishes.
 * 			Displays a debug message.
 * 
 */

FragTrap::~FragTrap(void)
{
	std::cout << GREEN_CHILD2 << "FragTrap Destructor called for the name " 
				<< this->_name << RESET << std::endl;	
}

//------------------------OPERATORS                     ------------------------

/**
 * @brief	Copy assignment operator.
 * 			Replaces this FragTrap with a copy of another.
 * 			Delegates the copy of ClapTrap attributes to ClapTrap's
 * 			assignment operator
 * 
 * @param other	The FragTrap instance to copy from
 * @return Reference to this updated FragTrap.
 */

FragTrap	&FragTrap::operator=(const FragTrap& other)
{
	std::cout << GREEN_CHILD2 << "FragTrap Assignation operator called." 
				<< RESET << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);	
}

//------------------------PUBLIC METHODS                ------------------------

/**
 * @brief	Request a positive high-five.
 *          Prints a message.
 * 
 */

void	 FragTrap::highFivesGuys(void)
{
    std::cout << BLUE_CHILD2 << "Give me five!" << RESET << std::endl;
}
