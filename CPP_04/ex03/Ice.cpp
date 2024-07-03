/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:55:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 14:50:35 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMaterial(this->type) {
	std::cout << "Ice created!" << std::endl;
}

Ice::Ice(const Ice& refObj) : AMaterial(refObj) {
	std::cout << "Ice created!" << std::endl;
}

Ice& operator=(const Ice& refObj) {
	// if (this != &refObj)
	// {
	// 	this->type = refObj.type;
	// }
	std::cout << "Assignment operator called on Ice" << std::endl;
	return (*this);
}

Ice::~Ice() {
	std:cout << "Ice destroyed" << std::endl;
}

AMateria* clone() const {
	AMateria *ice = new Ice;

	return(ice);
}

void Ice::use(ICharacter& target) {
	std::out << "* shoots an ice bolt at " << target->name << " *" << std::endl;	
}
