/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:15:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 14:41:15 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("") {
	std::cout << "AMateria created!" << std::endl;
}

AMateria::AMateria(const AMateria& refObj) : type(refObj->type) {
	std::cout << "AMateria constructed!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& refObj) {
	if (this != &refObj)
	{
		this->type = refObj.type;
	}
	std::cout << "Assignment operator called on AMateria" << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "Amateria constructed with type " << this->type << "." << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << std::endl;
}

std::string const & getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* AMateria use function called on " << target->name << " *" << std::endl;
}
