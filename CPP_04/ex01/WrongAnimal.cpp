/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:59:00 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 11:37:58 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "Generic WrongAnimal";
	std::cout << "WrongAnimal constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& refObj) {
	this->type = refObj.type;
	std::cout << "WrongAnimal constructed!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& refObj) {
	if (this != &refObj) {
		this->type = refObj.type;
	}
	std::cout << "Assignment operator called on WrongAnimal" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructed!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
		std::cout << "Generic sound of WrongAnimal" << std::endl;
}