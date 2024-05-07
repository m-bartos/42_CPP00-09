/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 09:50:40 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string newName) : name(newName) {}

Zombie::~Zombie() {
	std::cout << name << std::endl;
}

void	Zombie::setName(std::string newName) {
	name = newName;
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}