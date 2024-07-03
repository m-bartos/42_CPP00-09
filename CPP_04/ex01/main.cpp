/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:54:31 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 11:26:26 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }

int	main() {
	{
		std::cout << "----- START OF FIRST TEST SECTION -----" << std::endl;
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
		std::cout << "----- END OF FIRST TEST SECTION -----" << std::endl;
	}
	{
		std::cout << "----- START OF SECOND TEST SECTION -----" << std::endl;
		int	i = 0;
		const Animal*	animals[10];
		while (i < 5)
		{
			animals[i++] = new Cat();
			std::cout << std::endl;
		}
		while (i < 10)
		{
			animals[i++] = new Dog();
			std::cout << std::endl;
		}
		for (i = 0; i < 10;)
		{
			delete animals[i++];
			std::cout << std::endl;
		}
		std::cout << "----- END OF SECOND TEST SECTION -----" << std::endl;
	}
	{
		std::cout << "----- START OF THIRD TEST SECTION -----" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
		std::cout << "----- END OF THIRD TEST SECTION -----" << std::endl;
	}
	return (0);
}
