/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 11:08:20 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal() {
	this->type = "DOG";
	std::cout << "Dog constructed!" << std::endl;
}

Dog::Dog(const Dog &refObj) : Animal(refObj) {
	std::cout << "Dog constructed!" << std::endl;
}

Dog& Dog::operator=(const Dog &refObj) {
	if (this != &refObj)
	{
		this->type = refObj.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Barg, barg!" << std::endl;
}