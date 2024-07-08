/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 11:33:10 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "CAT";
	std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat &refObj) : Animal(refObj) {
	std::cout << "Cat constructed!" << std::endl;
}

Cat& Cat::operator=(const Cat &refObj) {
	if (this != &refObj) {
		this->type = refObj.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed!" << std::endl;
}

// A function that is virtual in a base class is implicitly virtual in its
// derived classes. When a derived class overrides a virtual, the parame-
// ters in the base and derived classes must match exactly.
void Cat::makeSound() const {
	std::cout << "Meow, meow!" << std::endl;
}