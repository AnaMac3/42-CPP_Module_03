/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:36:05 by root              #+#    #+#             */
/*   Updated: 2025/09/20 13:01:22 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main()
{
	ScavTrap player1("Robot");

	std::cout << std::endl;

	player1.attack("target1");
	player1.takeDamage(50); //hit points = 50
	player1.beRepaired(40); //hit points = 90

	//gastar energyPoints:
	for (int i = 0; i < 49; i ++)
		player1.attack("target");
	//cannot attack, energy points not enough
	
	std::cout << std::endl;
	
	player1.guardGate();

	std::cout << std::endl;
		
	ScavTrap playerB(player1); //copy constructor
	//ClapTrap playerB=player1; //==
	playerB.beRepaired(4); //cannot be repaired, energy points not enough
	
	std::cout << std::endl;
	
	ScavTrap player2("Robot2");
	player2.takeDamage(12); //hit points
	player2.takeDamage(4);
	player2.beRepaired(4);

	std::cout << std::endl;

	ScavTrap player3;
	player3 = player2; //assignment operator, without copy constructor
	player3.attack("another target"); //cannot

	std::cout << std::endl;

	return (0);
}
