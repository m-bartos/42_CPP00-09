/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:43 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 09:50:44 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie	*horde;
	int		N = 5;

	horde = zombieHorde(N, "ARNOLD");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}