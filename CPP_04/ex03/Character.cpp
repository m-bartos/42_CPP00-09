/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:58:32 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/05 15:03:55 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria* Character::floor[FLOOR_SIZE];

Character::Character() : name("") {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& refObj) : name(refObj.getName()) {
	for (int i = 0; i < 4; i++)
		inventory[i] = refObj.inventory[i]->clone();
}

Character& Character::operator= (const Character& refObj)
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
			inventory[i] = NULL;
		}
		inventory[i] = refObj.inventory[i]->clone();
	}
	return (*this);
}

Character::Character(std::string name) : name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
};

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (inventory[i] != NULL) {
			if (inventory[i]->getIsEquipped()) {
				std::cout << "Character inventory delete at index = " << i << std::endl;
				for(int j = 0; j < FLOOR_SIZE; j++) {
					if (floor[j] == inventory[i]) {
						floor[j] = NULL;
					}
				}
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
	// std::cout << "Character destroyed" << std::endl;
}

void Character::equip(AMateria* m) {
	if (m->getIsEquipped()) {
		std::cout << "Item cannot be equipped. Someone else has it in his inventory" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			m->setIsEquipped(true);
			return ;
		}
	}
	std::cout << "Inventory full. Unequip something first" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	if (inventory[idx] != NULL) {
		for(int i = 0; i < FLOOR_SIZE; i++) {
			if (floor[i] == inventory[idx]) {
				// std::cout << "AMateria is already on the floor" << std::endl;
				inventory[idx]->setIsEquipped(false);
				inventory[idx] = NULL;
				return ;
			}
		}
		for (int i = 0; i < FLOOR_SIZE; i++)
		{
			if (floor[i] == NULL) {
				floor[i] = inventory[idx];
				inventory[idx]->setIsEquipped(false);
				inventory[idx] = NULL;
				return ;
			}
		}
		std::cout << "Floor is full, cannot unequip AMateria - type: " << inventory[idx]->getType() << std::endl;
		std::cout << "Increase the FLOOR_SIZE in Character.hpp" << std::endl;
	}
	else
		std::cout << "Nothing to unequip" << std::endl;
}


void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	if (inventory[idx] != NULL)
		this->inventory[idx]->use(target);
	else
		std::cout << "Cannot call use func: nothing on index = " << idx << std::endl;
}

std::string	const & Character::getName() const {
	return(this->name);
}

void Character::clearFloor() {
	for (int i = 0; i < FLOOR_SIZE; i++) {
		if (floor[i] != NULL && !(floor[i]->getIsEquipped())) {
				delete floor[i];
				floor[i] = NULL;
		}
	}
}
