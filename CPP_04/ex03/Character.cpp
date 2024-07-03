/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:58:32 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 15:51:18 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("") {
	for (int i = 0, i < 4, i++)
		inventory[i] = NULL;
}

Character::Character(const Character& refObj) : name(refObj->name) {
	for (int i = 0, i < 4, i++)
		inventory[i] = refObj.inventory[i]->clone();
}

Character& Character::operator = (const Character& refObj)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i] != NULL)
			delete inventory[i];
	for (int i = 0; i < 4; i++)
		inventory[i] = refObj.inventory[i]->clone();
	return (*this);
}

Character::Character(std::string name) : name(name) {
	for (int i = 0, i < 4, i++)
		inventory[i] = NULL;
};

Character::~Character() {
	std::cout << "Character destroyed" << std::endl;
}

void Character::equip(AMateria* m) {
	for (int i = 0, i < 4, i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full. Unequip something first" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	if (inventory[idx] != NULL)
		inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Not a valid index" << std::endl;
		return ;
	}
	if (inventory[i] == NULL)
		this->AMateria[idx]->use(target);
	else
		std::cout << "Index " << idx << " is already taken." << std::endl;
}