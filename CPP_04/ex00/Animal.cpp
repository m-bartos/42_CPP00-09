/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:59:19 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/03 14:49:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "";
	std::cout << "Animal constructed!" << std::endl;
}

Animal::Animal(const Animal& refObj) {
	this->type = refObj.type;
	std::cout << "Animal constructed!" << std::endl;
}

Animal& Animal::operator=(const Animal& refObj) {
	if (this != &refObj)
	{
		this->type = refObj.type;
	}
	std::cout << "Assignment operator called on Animal" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructed!" << std::endl;
}

std::string Animal::getType() const {
	return (type);
}

void Animal::makeSound() const {
		std::cout << "Generic sound" << std::endl;
}

