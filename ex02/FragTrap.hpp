/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:13:08 by root              #+#    #+#             */
/*   Updated: 2025/09/20 12:21:07 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define GREEN_CHILD2	"\033[4;32m"
# define BLUE_CHILD2	"\033[4;34m"

/**
 * @class	FragTrap
 * @brief	A specialized ClapTrap ...
 * 
 */

class   FragTrap : public ClapTrap
{
    public:
		FragTrap(),
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap(void);

		void	 highFivesGuys(void);
};

#endif