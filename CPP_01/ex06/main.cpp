/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/08 15:02:21 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);

	return (0);
}