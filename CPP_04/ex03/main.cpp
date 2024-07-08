/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:29:24 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/08 11:18:23 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "----- Start of first section ------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		AMateria* tmp2;
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		Character::clearUnequippedItems();
		std::cout << "----- End of first section ------" << std::endl;
	}
	{
		std::cout << "----- Start of second section ------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		AMateria* tmp2;
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		me->unequip(0);
		me->unequip(1);
		me->equip(tmp1);
		me->equip(tmp2);
		me->unequip(0);
		me->unequip(1);
		me->equip(tmp1);
		me->equip(tmp2);
		me->unequip(0);
		me->unequip(1);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		Character::clearUnequippedItems();
		std::cout << "----- End of second section ------" << std::endl;
	}
	{
		std::cout << "----- Start of third section ------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		for(int i = 0; i < 43; i++)
		{
			tmp1 = src->createMateria("ice");
			me->equip(tmp1);
			me->unequip(0);
		}
		delete me;
		delete src;
		Character::clearUnequippedItems();
		std::cout << "----- End of third section ------" << std::endl;
	}
	return (0);
}