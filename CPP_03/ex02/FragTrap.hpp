/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:07:21 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/31 09:18:41 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(const FragTrap&);
	FragTrap(std::string newName);
	FragTrap& operator=(const FragTrap&);
	~FragTrap();

	void	highFiveGuys(void);
	// void guardGate();
	// void	attack(const std::string& target);
};

#endif