/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:01:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/05 10:07:09 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this-> attackDamage = 20;
	std::cout << "ScavTrap created (with default ScavTrap constructor)." << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this-> attackDamage = 20;
	std::cout << "ScavTrap \"" << newName << "\" created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& oldObj) : ClapTrap(oldObj) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& oldObj) {
	if (this != &oldObj)
	{
		this->name = oldObj.name;
		this->hitPoints = oldObj.hitPoints;
		this->energyPoints = oldObj.hitPoints;
		this->attackDamage = oldObj.attackDamage;
	}
	std::cout << "ScavTrap \"" << this->name << "\" copied using copy assignment operator." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " is destroyed." << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " does not have enough energy to attack " << target << "." << std::endl;
}