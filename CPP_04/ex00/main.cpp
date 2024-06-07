/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:54:31 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 11:23:08 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
	const Animal*	newAnimal = new Animal();
	const Animal*	Ralf = new Dog();
	const Animal*	Mice = new Cat();

	std::cout << std::endl;
	std::cout << "Type is \"" << newAnimal->getType() << "\"" << std::endl;
	newAnimal->makeSound();
	std::cout << std::endl;
	std::cout << "Type is \"" << Ralf->getType() << "\"" << std::endl;
	Ralf->makeSound();
	std::cout << std::endl;
	std::cout << "Type is \"" << Mice->getType() << "\"" << std::endl;
	Mice->makeSound();
	std::cout << std::endl;

	delete newAnimal;
	delete Ralf;
	delete Mice;
	std::cout << std::endl;

	const WrongAnimal* wrongMice = new WrongCat();
	std::cout << std::endl;
	std::cout << "Type is \"" << wrongMice->getType() << "\"" << std::endl;
	wrongMice->makeSound(); // will output sound of WrongAnimal not WrongCat
	std::cout << std::endl;

	delete wrongMice;
	return (0);
}