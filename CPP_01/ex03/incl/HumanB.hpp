/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:14:02 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 14:31:12 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string newName);
	~HumanB();
	void	setWeapon(Weapon& newWeapon);
	void	attack() const;

private:
	std::string	name;
	Weapon*		weapon;
};

#endif