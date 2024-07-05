/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:15:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/05 14:24:07 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type(""), isEquipped(false) {
	// std::cout << "AMateria created!" << std::endl;
}

AMateria::AMateria(const AMateria& refObj) : type(refObj.type), isEquipped(false) {
	// std::cout << "AMateria constructed!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& refObj) {
	if (this != &refObj)
	{
		this->type = refObj.type;
	}
	// std::cout << "Assignment operator called on AMateria" << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const & type) : type(type), isEquipped(false) {
	// std::cout << "Amateria constructed with type " << this->type << "." << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destroyed" << std::endl;
}

void AMateria::setIsEquipped(bool value) {
	this->isEquipped = value;
}

bool AMateria::getIsEquipped() {
	return (isEquipped);
}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* AMateria use function called on " << target.getName() << " *" << std::endl;
}