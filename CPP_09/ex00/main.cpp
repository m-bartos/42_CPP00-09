/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:21:37 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/06 16:13:35 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange btcEx;
	if (argc != 2)
		std::cerr << "Incorrect input." << std::endl;
	else
	{
		std::cout << argv[1] << std::endl;
		btcEx.LoadDB();
		// btcEx.printDatabase();
		btcEx.LoadInput(argv[1]);
	}
	return (0);
}
