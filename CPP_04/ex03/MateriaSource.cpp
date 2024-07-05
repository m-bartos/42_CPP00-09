/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:56:10 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/05 10:52:17 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& refObj)
{
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
		inventory[i] = refObj.inventory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator = (const MateriaSource& refObj)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
		inventory[i] = refObj.inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (materia != NULL) {
		for (int i = 3; i >= 0; i--) {
			if (inventory[i] == NULL) {
				inventory[i] = materia;
				return ;
			}
		}
		std::cout << "Full materia inventory" << std::endl;
		return ;
	}
	std::cout << "Materia to learn is empty" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	AMateria	*temp;
	
	for (int i = 3; i >= 0; i--) {
		if (inventory[i] != NULL && type == inventory[i]->getType()) {
			temp = inventory[i]->clone();
			return (temp);
		}
	}
	std::cout << "Type unknown" << std::endl;
	return (NULL);
}