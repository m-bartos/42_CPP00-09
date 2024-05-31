/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:07:52 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 09:19:09 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this-> attackDamage = 30;
	std::cout << "FragTrap created (with default ScavTrap constructor)." << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this-> attackDamage = 30;
	std::cout << "FragTrap \"" << newName << "\" created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& oldObj) : ClapTrap(oldObj) {
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& oldObj) {
	if (this != &oldObj)
	{
		this->name = oldObj.name;
		this->hitPoints = oldObj.hitPoints;
		this->energyPoints = oldObj.hitPoints;
		this->attackDamage = oldObj.attackDamage;
	}
	std::cout << "FragTrap \"" << this->name << "\" copied using copy assignment operator." << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " is destroyed." << std::endl;
}

// void FragTrap::guardGate() {
// 	std::cout << "FragTrap " << this->name << " is in Gate keeper mode." << std::endl;
// }

// void FragTrap::attack(const std::string& target) {
// 	if (this->energyPoints > 0)
// 	{
// 		this->energyPoints--;
// 		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
// 	}
// 	else
// 		std::cout << "FragTrap " << this->name << " does not have enough energy to attack " << target << "." << std::endl;
// }

void FragTrap::highFiveGuys(void) {
	std::cout << "High five!" << std::endl;
}