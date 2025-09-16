/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:13:08 by root              #+#    #+#             */
/*   Updated: 2025/09/16 10:07:58 by root             ###   ########.fr       */
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
		~FragTrap(void);
		FragTrap& operator=(const FragTrap& other);

		void	 highFivesGuys(void);
};

#endif