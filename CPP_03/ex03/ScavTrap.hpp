/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:01:37 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 10:54:26 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap();
	ScavTrap(const ScavTrap&);
	ScavTrap(std::string newName);
	ScavTrap& operator=(const ScavTrap&);
	~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
};

#endif