/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 11:08:14 by mbartos          ###   ########.fr       */
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
	if (this != &refObj)
	{
		this->type = refObj.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructed!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow, meow!" << std::endl;
}