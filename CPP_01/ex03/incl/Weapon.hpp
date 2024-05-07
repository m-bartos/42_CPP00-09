/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:13:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 12:50:00 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {

public:
	Weapon(std::string newType);
	~Weapon();

	std::string	getType() const;
	void		setType(std::string newType);

private:
	std::string	type;
};

#endif