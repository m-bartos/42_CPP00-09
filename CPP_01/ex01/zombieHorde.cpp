/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:15:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 09:50:29 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde (int N, std::string name) {
	Zombie*	ZombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		ZombieHorde[i].setName(name);

	return (ZombieHorde);
}