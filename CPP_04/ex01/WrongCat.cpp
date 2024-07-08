/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:03:28 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 11:38:04 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructed!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &refObj) : WrongAnimal(refObj) {
	std::cout << "WrongCat constructed!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &refObj) {
	if (this != &refObj) {
		this->type = refObj.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructed!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong meow, wrong meow!" << std::endl;
}
