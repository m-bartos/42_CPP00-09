/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:39:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/20 15:03:16 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main () {

	PhoneBook adresar;
	std::string command;
	int phoneNumber;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	
	while (command != "EXIT")
	{
		std::cout << "What you want to do? Type ADD/SEARCH/EXIT" << std::endl;
		std::cin >> command;
		if (command == "EXIT")
		{
			break;
		}
		if (command == "ADD")
		{
			std::cout << "Enter phone number: " << std::endl;
			std::cin >> phoneNumber;
			std::cout << "Enter first name: " << std::endl;
			std::cin >> firstName;
			std::cout << "Enter last name: " << std::endl;
			std::cin >> lastName;
			std::cout << "Enter nickname: " << std::endl;
			std::cin >> nickName;
			std::cout << "Enter darkest secret: " << std::endl;
			std::cin >> darkestSecret;
		}
		Contact firstContact (phoneNumber, firstContact, lastName, nickName, darkestSecret);
	}
	return (0);
}