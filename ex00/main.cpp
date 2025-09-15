/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:36:05 by root              #+#    #+#             */
/*   Updated: 2025/09/15 16:40:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
	ClapTrap player1("Robot");

	player1.attack("target1");
	player1.takeDamage(5); //hit points = 5
	player1.beRepaired(4); //hit points = 9
	player1.attack("target2");
	player1.attack("target3");
	player1.attack("target4");
	player1.attack("target5");
	player1.attack("target6");
	player1.attack("target7");
	player1.attack("target8");
	player1.attack("target9");
	player1.attack("target10"); //cannot attack, energy points not enough
	
	std::cout << std::endl;
	
	ClapTrap playerB(player1); //copy constructor
	//ClapTrap playerB=player1; //==
	playerB.beRepaired(4); //cannot be repaired, anergy points not enough
	
	std::cout << std::endl;
	
	ClapTrap player2;
	player2.takeDamage(12); //hit points = -2
	player2.takeDamage(4); //already dead
	player2.beRepaired(4); //cannot be repaired

	std::cout << std::endl;

	ClapTrap player3;
	player3 = player2; //assignation operator, without copy constructor
	player3.attack("another target"); //cannot

	std::cout << std::endl;

	return (0);
}
