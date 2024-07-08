/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 13:44:52 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal() {
	this->type = "DOG";
	this->brain = new Brain();
	std::cout << "Dog constructed!" << std::endl;
}

Dog::Dog(const Dog &refObj) : Animal(refObj) {
	this->brain = new Brain(*refObj.brain);
	std::cout << "Dog constructed!" << std::endl;
}

Dog& Dog::operator=(const Dog &refObj) {
	if (this != &refObj) {
		this->type = refObj.type;
		*this->brain = *refObj.brain;
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Barg, barg!" << std::endl;
}

void Dog::printBrainAdress() const {
	std::cout << this->brain << std::endl;
}

void Dog::createIdea(std::string idea, int i) {
	if (i >= 0 && i < 100)
		this->brain->ideas[i] = idea;
	else
		std::cout << "Index out of range" << std::endl;
}

void Dog::printIdeas() {
	std::cout << "All ideas in brain: " << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->brain->ideas[i] != "")
			std::cout << "Idea = \'" << this->brain->ideas[i] << "\'" << " at index = " << i << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
}