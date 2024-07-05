/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/05 10:34:43 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice created!" << std::endl;
}

Ice::Ice(const Ice& refObj) : AMateria(refObj) {
	// std::cout << "Ice created!" << std::endl;
}

Ice& Ice::operator=(const Ice& refObj) {
	(void)refObj;
	// std::cout << "Assignment operator called on Ice" << std::endl;
	return (*this);
}

Ice::~Ice() {
	// std::cout << "Ice destroyed" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria *ice = new Ice;

	return(ice);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;	
}
