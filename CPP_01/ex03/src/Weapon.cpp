/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:13:07 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 14:06:35 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType) {};

Weapon::~Weapon() {
	std::cout << "Weapon \"" << type << "\" destructed" << std::endl;
};

const std::string&	Weapon::getType() const {
	return (type);
}

void	Weapon::setType(std::string newType) {
	type = newType;
}