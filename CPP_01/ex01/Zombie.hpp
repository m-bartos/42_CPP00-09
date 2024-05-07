/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:37 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 09:49:39 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie {

public:
	Zombie();
	Zombie(std::string newName );
	~Zombie();
	void	announce();
	void	setName(std::string newName);

private:
	std::string name;
};

Zombie*	newZombie(std::string name);
Zombie*	zombieHorde (int N, std::string name);
void	randomChump(std::string name);

#endif