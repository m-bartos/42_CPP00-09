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

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure created!" << std::endl;
}

Cure::Cure(const Cure& refObj) : AMateria(refObj) {
	// std::cout << "Cure created!" << std::endl;
}

Cure& Cure::operator=(const Cure& refObj) {
	(void)refObj;
	// std::cout << "Assignment operator called on Cure" << std::endl;
	return (*this);
}

Cure::~Cure() {
	// std::cout << "Cure destroyed" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria *cure = new Cure;

	return(cure);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;	
}
