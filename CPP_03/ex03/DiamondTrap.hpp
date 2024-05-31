/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:48:30 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 15:34:48 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap&);
	DiamondTrap(std::string newName);
	DiamondTrap& operator=(const DiamondTrap&);
	~DiamondTrap();

	using ScavTrap::attack;
	void whoAmI();

private:
	std::string name;
};

#endif