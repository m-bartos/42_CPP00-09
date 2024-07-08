/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:42 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 13:38:31 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:
	Dog();
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	~Dog();

	void makeSound() const;
	void printBrainAdress() const;
	void printIdeas();
	void createIdea(std::string idea, int i);

private:
	Brain* brain;
};

#endif