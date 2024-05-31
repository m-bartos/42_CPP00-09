/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:19:39 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 09:17:42 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {
	// ClapTrap firstClapTrap("First");

	// std::cout << "--------------------------------" << std::endl;
	// std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	// std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	// std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	// std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	// std::cout << "--------------------------------" << std::endl;

	// firstClapTrap.attack("Evaluator");
	// firstClapTrap.takeDamage(4);
	// firstClapTrap.beRepaired(2);

	// std::cout << "--------------------------------" << std::endl;
	// std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	// std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	// std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	// std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	// std::cout << "--------------------------------" << std::endl;

	// for (int i = 0; i < 9; i++)
	// 	firstClapTrap.attack("Evaluator");
	// firstClapTrap.beRepaired(2);

	// std::cout << "--------------------------------" << std::endl;
	// std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	// std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	// std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	// std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	// std::cout << "--------------------------------" << std::endl;

	std::cout << "Creating firstScavTrap: " << std::endl;
	ScavTrap firstScavTrap("ScavTrap1");
	
	std::cout << std::endl;
	std::cout << "Copying firstScavTrap to new secondScavTrap: " << std::endl;
	ScavTrap secondScavTrap(firstScavTrap);
	
	std::cout << std::endl;
	std::cout << "Creating thirdScavTrap without any name: " << std::endl;
	ScavTrap thirdScavTrap;

	std::cout << std::endl;
	std::cout << "Copying attributes from secondScavTrap to thirdScavTrap: " << std::endl;
	thirdScavTrap = secondScavTrap;

	std::cout << std::endl;

	firstScavTrap.attack("NOTHING_1");
	secondScavTrap.attack("NOTHING_2");
	thirdScavTrap.attack("NOTHING_3");

	std::cout << std::endl;
	std::cout << "Printing name of secondScavTrap: " << secondScavTrap.getName() << std::endl;
	std::cout << std::endl;

	FragTrap frag1("Frag1");

	frag1.highFiveGuys();
	frag1.attack("NOOONE");

	return (0);
}