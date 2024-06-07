/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:54:31 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 10:18:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main() {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	return 0;
// }

int	main() {
	const Animal	newAnimal;
	const Dog		Ralf;
	const Cat		Mice;

	std::cout << std::endl;
	std::cout << "Type is \"" << newAnimal.getType() << "\"" << std::endl;
	newAnimal.makeSound();
	std::cout << std::endl;
	std::cout << "Type is \"" << Ralf.getType() << "\"" << std::endl;
	Ralf.makeSound();
	std::cout << std::endl;
	std::cout << "Type is \"" << Mice.getType() << "\"" << std::endl;
	Mice.makeSound();
	std::cout << std::endl;
	return (0);
}
