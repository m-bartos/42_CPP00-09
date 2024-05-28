/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:19:39 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/28 13:58:34 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main () {
	ClapTrap firstClapTrap("First");

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;

	firstClapTrap.attack("Evaluator");
	firstClapTrap.takeDamage(4);
	firstClapTrap.beRepaired(2);

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;

	for (int i = 0; i < 9; i++)
		firstClapTrap.attack("Evaluator");
	firstClapTrap.beRepaired(2);

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Stats of ClapTrap " << firstClapTrap.getName() << ":" << std::endl;
	std::cout << "Hitpoints: " << firstClapTrap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << firstClapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << firstClapTrap.getAttackDamage() << std::endl;
	std::cout << "--------------------------------" << std::endl;

	return (0);
}