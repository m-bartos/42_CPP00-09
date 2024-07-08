/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 13:48:08 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "CAT";
	this->brain = new Brain();
	std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const Cat &refObj) : Animal(refObj) {
	this->brain = new Brain();
	std::cout << "Cat constructed!" << std::endl;
}

Cat& Cat::operator=(const Cat &refObj) {
	if (this != &refObj) {
		this->type = refObj.type;
		*this->brain = *refObj.brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructed!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow, meow!" << std::endl;
}

void Cat::printBrainAdress() const {
	std::cout << this->brain << std::endl;
}

void Cat::createIdea(std::string idea, int i) {
	if (i >= 0 && i < 100)
		this->brain->ideas[i] = idea;
	else
		std::cout << "Index out of range" << std::endl;
}

void Cat::printIdeas() {
	std::cout << "All ideas in brain: " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->brain->ideas[i] != "")
			std::cout << "Idea = \'" << this->brain->ideas[i] << "\'" << " at index = " << i << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
}