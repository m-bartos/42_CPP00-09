/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:40:41 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/06 11:35:44 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	std::string	str;
	
	if (argc >= 2)
	{
		// for each string in **argv, upper the string letter by letter and print it afterwards
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
				str[j] = std::toupper(str[j]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
