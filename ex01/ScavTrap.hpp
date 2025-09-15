/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:00:41 by root              #+#    #+#             */
/*   Updated: 2025/09/15 18:07:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define GREEN_CHILD	"\033[42m"
# define BLUE_CHILD		"\033[44m"
# define YELLOW_CHILD	"\033[43m"
# define RED_CHILD		"\033[41m"

/**
 * @class	ScavTrap
 * @brief	A specialized ClapTrap with enhanced hit points, energy, and attack
 * 			damage.
 * 			ScavTrap inherits from ClapTrap, reusing its attributes and
 * 			constructors. Overrides some behaviours and provides its own
 * 			initialization values.
 * 			The class overrides the attack() method. All constructors and
 * 			destructor also display colored debug messages to show the order
 * 			of construction and destruction.
 * 			Introduces a unique method: guardGate().
 * 
 */

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap(void);

		void	attack(const std::string& target);

		void	guardGate();

};

#endif
