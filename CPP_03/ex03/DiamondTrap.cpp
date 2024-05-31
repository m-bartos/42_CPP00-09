/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:58:12 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 15:50:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
The order in which base classes are constructed depends on the order in which they
appear in the class derivation list. The order in which they appear in the construc-
tor initializer list is irrelevant.
*/
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap created (with default ScavTrap constructor)." << std::endl;
	ScavTrap tempScavTrap;
	
	name = "";
	ClapTrap::name = "_clap_name";
	this->energyPoints = tempScavTrap.getEnergyPoints();
}

DiamondTrap::DiamondTrap(std::string newName) : ScavTrap(newName), FragTrap(newName) {
	std::cout << "DiamondTrap \"" << newName << "\" created." << std::endl;

	ScavTrap tempScavTrap;
	
	name = newName;
	ClapTrap::name = newName + "_clap_name";
	this->energyPoints = tempScavTrap.getEnergyPoints();
}

/*
As is the case for single inheritance, classes with multiple bases that define their
own copy/move constructors and assignment operators must copy, move, or as-
sign the whole object. The base parts of a multiply derived class
are automatically copied, moved, or assigned only if the derived class uses the
synthesized versions of these members. In the synthesized copy-control members,
each base class is implicitly constructed, assigned, or destroyed, using the corre-
sponding member from that base class.
*/
DiamondTrap::DiamondTrap(const DiamondTrap& oldObj) : ClapTrap(oldObj), ScavTrap(oldObj), FragTrap(oldObj) {
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& oldObj) {
	if (this != &oldObj)
	{
		this->name = oldObj.name;
		this->hitPoints = oldObj.hitPoints;
		this->energyPoints = oldObj.hitPoints;
		this->attackDamage = oldObj.attackDamage;
		this->ClapTrap::name = oldObj.ClapTrap::name;
	}
	std::cout << "DiamondTrap \"" << this->name << "\" copied using copy assignment operator." << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " is destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << ", " << "ClapTrap name: " << ClapTrap::name << std::endl;
}