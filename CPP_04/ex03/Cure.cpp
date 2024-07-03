/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 14:47:43 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMaterial(this->type) {
	std::cout << "Cure created!" << std::endl;
}

Cure::Cure(const Cure& refObj) : AMaterial(refObj) {
	std::cout << "Cure created!" << std::endl;
}

Cure& operator=(const Cure& refObj) {
	// if (this != &refObj)
	// {
	// 	this->type = refObj.type;
	// }
	std::cout << "Assignment operator called on Cure" << std::endl;
	return (*this);
}

Cure::~Cure() {
	std:cout << "Cure destroyed" << std::endl;
}

AMateria* clone() const {
	AMateria *cure = new Cure;

	return(cure);
}

void Cure::use(ICharacter& target) {
	std::out << "* heals " << target->name << "’s wounds *" << std::endl;	
}
