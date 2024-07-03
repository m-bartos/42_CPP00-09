/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:36:58 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 10:45:45 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed!" << std::endl;
}

Brain::Brain(const Brain &refObj) {
	std::copy(refObj.ideas, refObj.ideas + 100, this->ideas);
	std::cout << "Brain constructed with copy constructor!" << std::endl;
}

Brain& Brain::operator=(const Brain &refObj) {
	if (this != &refObj)
	{
		std::copy(refObj.ideas, refObj.ideas + 100, this->ideas);
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Auch! Brain destructed!" << std::endl;
}