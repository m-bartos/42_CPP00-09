/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:39:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 21:13:18 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

int	main () {

	PhoneBook	adresar;
	std::string	command;
	long long	phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	
	while (command != "EXIT")
	{
		std::cout << "What you want to do? Type ADD/SEARCH/EXIT" << std::endl;
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			// saved contact cannot have empty fields!
			std::cout << "Enter phone number: " << std::endl;
			std::cin >> phoneNumber;
			while (std::cin.fail())
			{
				std::cout << "Invalid input. Please enter a valid long long number: " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> phoneNumber;
			}
			std::cout << "Enter first name: " << std::endl;
			std::cin >> firstName;
			std::cout << "Enter last name: " << std::endl;
			std::cin >> lastName;
			std::cout << "Enter nickname: " << std::endl;
			std::cin >> nickName;
			std::cout << "Enter darkest secret: " << std::endl;
			std::cin >> darkestSecret;
			adresar.addContact(Contact(phoneNumber, firstName, lastName, nickName, darkestSecret));
		}
		else if (command == "SEARCH")
		{
			std::cout << "Searching..." << std::endl;
			adresar.searchContact();
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}