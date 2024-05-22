/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:14:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 14:32:22 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {

public:
	HumanA(std::string newName, Weapon& newWeapon);
	~HumanA();
	// setter is not necessary for this ex - just testing how references work
	// void	setWeapon(Weapon& newWeapon);
	void	attack() const;

private:
	std::string	name;
	Weapon&		weapon;
};

#endif