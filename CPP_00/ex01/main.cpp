/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:39:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/04/03 10:03:58 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

bool	isValidPhoneNumber(std::string phoneNumber)
{
	int	i;

	i = 0;
	if (phoneNumber[i] == '+')
		i++;
	while (phoneNumber[i])
	{
		if (phoneNumber[i] >= '0' && phoneNumber[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

int	main () {

	PhoneBook	phoneBook;
	std::string	command;
	std::string	phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;
	
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "--------------Phonebook--------------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	while (command != "EXIT")
	{
		std::cout << "What you want to do? Type ADD/SEARCH/EXIT" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(1);
		}
		if (command == "ADD")
		{
			// saved contact cannot have empty fields!
			std::cout << "Enter phone number: " << std::endl;
			std::cin >> phoneNumber;
			// Check for EOF (CTRL+D)
			if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(1);
			}
			// Check if it is a valid number - + at the beggining and then just numbers
			while (!isValidPhoneNumber(phoneNumber))
			{
				std::cout << "Invalid input. Please enter a valid phone number: " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> phoneNumber;
			}
			std::cout << "Enter first name: " << std::endl;
			std::cin >> firstName;
			if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(1);
			}
			std::cout << "Enter last name: " << std::endl;
			std::cin >> lastName;
			if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(1);
			}
			std::cout << "Enter nickname: " << std::endl;
			std::cin >> nickName;
			if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(1);
			}
			std::cout << "Enter darkest secret: " << std::endl;
			std::cin >> darkestSecret;
			if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(1);
			}
			phoneBook.addContact(Contact(phoneNumber, firstName, lastName, nickName, darkestSecret));
		}
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}