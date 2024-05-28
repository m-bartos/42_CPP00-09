/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:01:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/28 14:16:31 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20) {
	std::cout << "ScavTrap created." << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName, 100, 50, 20) {
	std::cout << "ScavTrap " << newName << " created." << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap&) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& oldObj) {
	if (this != &oldObj)
	{
		name = oldObj.name;
		hitPoints = oldObj.hitPoints;
		energyPoints = oldObj.hitPoints;
		attackDamage = oldObj.attackDamage;
	}
	std::cout << "ClapTrap \"" << this->name << "\" copied using copy assignment operator." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " is destroyed." << std::endl;
}

void guardGate();