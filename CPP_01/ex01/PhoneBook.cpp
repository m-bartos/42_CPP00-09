/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:33 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/20 15:03:54 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

	PhoneBook::PhoneBook() {
		std::cout << "Phonebook created." << std::endl;
	};

	PhoneBook::~PhoneBook() {
		std::cout << "Phonebook destroyed." << std::endl;
	};

	// Contact::Contact() {
	// 	std::cout << "Contact created." << std::endl;
	// };

	Contact::Contact(int phoneNumber, std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret) : phoneNumber(phoneNumber), firstName(firstName), lastName(lastName), nickName(nickName), darkestSecret(darkestSecret) {
		std::cout << "Contact created2." << std::endl;
		
	};


	Contact::~Contact() {
		std::cout << "Contact deleted." << std::endl;
	};