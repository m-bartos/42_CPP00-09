/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:04:52 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/29 10:37:23 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &oldObj) {
	name = oldObj.name;
	hitPoints = oldObj.hitPoints;
	energyPoints = oldObj.hitPoints;
	attackDamage = oldObj.attackDamage;
	std::cout << "ClapTrap \"" << this->name << "\" copied." << std::endl;
}

ClapTrap::ClapTrap(std::string newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap \"" << this->name << "\" created." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& oldObj) {
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

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap \"" << this->name << "\" destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " does not have enough energy to attack " << target << "." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " is allready dead. But:" << std::endl;
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage. Now have " << this->hitPoints << " hitpoints." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " hitpoints. Now have " << this->hitPoints << " hitpoints." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " does not have enough energy to repair." << std::endl;
}
