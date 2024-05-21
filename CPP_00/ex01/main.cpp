/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:39:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/21 13:30:45 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main () {
	std::string	command;
	PhoneBook	phoneBook;

	std::cout << BOLD;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "--------------Phonebook--------------" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << RESET;

	while (command != "EXIT")
	{
		std::cout << std::endl;
		std::cout << BOLD << "What you want to do? Type ADD/SEARCH/EXIT" << RESET << std::endl;
		std::getline(std::cin, command);
		if (PhoneBook::IsEofOrFail())
			return (1);
		if (command == "ADD")
		{
			if (phoneBook.tryToAddContact() == 1)
				return (1);
		}
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}