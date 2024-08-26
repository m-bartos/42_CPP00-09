/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/26 11:57:20 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main (int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Invalid input. Not enough arguments.");

		PmergeMe sorting;

		sorting.Sort(argc, argv);
		std::cout << "Final sorted: " << std::endl;
		sorting.PrintNumbersInContainer();
		// sorting.PrintNumbersInPairs();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	return (0);
}