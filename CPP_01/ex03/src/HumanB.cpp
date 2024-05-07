/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:14:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 14:32:07 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName) {
	this->weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << "Human B called \"" << name << "\" destructed" << std::endl;
}

void	HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}

void	HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}