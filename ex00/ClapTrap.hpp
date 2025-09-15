/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:51:21 by root              #+#    #+#             */
/*   Updated: 2025/09/15 16:40:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>
# include <iostream>



/**
 * @class	Claptrap
 * @brief	A class representing a combat robot with hit points, energy
 * 			points, and attack damage.
 * 			ClapTrap perform 3 main actions:
 * 			- Attack another target (consumes energey points)
 * 			- Take damage (reduces hit points)
 * 			- Repair itself (restores hit points, consumes energy)
 * 			
 * 			The class provides constructors for default, named, and copy
 * 			initialization, as well as an assignment operator and destructor.
 * 
 */

class   ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif