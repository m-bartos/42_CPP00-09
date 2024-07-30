/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/30 16:48:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

int	main()
{
	Span testSpan(10);

	try
	{
		testSpan.addNumber(INT_MIN);
		testSpan.addNumber(INT_MAX);
		testSpan.addNumber(0);
		testSpan.addNumber(-1);
		testSpan.printNumbers();
		std::cout << testSpan.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	return (0);
}