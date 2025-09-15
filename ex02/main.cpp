/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:36:05 by root              #+#    #+#             */
/*   Updated: 2025/09/15 18:31:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

int main()
{
	FragTrap player1("Robot");

	player1.attack("target1");
	player1.takeDamage(50); //hit points = 50
	player1.beRepaired(40); //hit points = 90

	//gastar energyPoints:
	for (int i = 0; i < 99; i ++)
		player1.attack("target");
	//cannot attack, energy points not enough
	
	std::cout << std::endl;
	
	player1.highFivesGuys();

	std::cout << std::endl;
	
	//ESTO DEBERIA SER DIFERENTE?
	
	FragTrap playerB(player1); //copy constructor
	//ClapTrap playerB=player1; //==
	playerB.beRepaired(4); //cannot be repaired, anergy points not enough
	
	std::cout << std::endl;
	
	FragTrap player2;
	player2.takeDamage(120); //hit points = -20
	player2.takeDamage(4); //already dead
	player2.beRepaired(4); //cannot be repaired

	std::cout << std::endl;

	FragTrap player3;
	player3 = player2; //assignation operator, without copy constructor
	player3.attack("another target"); //cannot

	std::cout << std::endl;

	return (0);
}
