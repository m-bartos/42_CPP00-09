/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:14:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 14:22:47 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon) : name(newName), weapon(newWeapon) {}

HumanA::~HumanA() {
	std::cout << "Human A called \"" << name << "\" destructed" << std::endl;
}

// void	HumanA::setWeapon(Weapon& newWeapon)
// {
// 	weapon = newWeapon;
// }

void	HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}