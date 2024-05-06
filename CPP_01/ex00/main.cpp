/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:43 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/06 16:16:44 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Arnold;

	Arnold = newZombie("ARNOLD");
	Arnold->announce();

	randomChump("Elias");

	delete Arnold;

	return (0);
}