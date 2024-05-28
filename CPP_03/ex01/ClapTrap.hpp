/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:51:41 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/28 14:15:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap&);
	ClapTrap(std::string newName, int newHitPoints, int newEnergyPoints, int newAttackDamage);
	ClapTrap& operator=(const ClapTrap&);
	~ClapTrap();

	std::string getName() {return name;};
	int getHitPoints() {return hitPoints;};
	int getEnergyPoints() {return energyPoints;};
	int getAttackDamage() {return attackDamage;};

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
};


#endif