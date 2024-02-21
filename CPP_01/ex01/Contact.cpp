/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:20:20 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 11:24:53 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

	Contact::Contact() {
		phoneNumber = 0;
		firstName = "";
		lastName = "";
		nickName = "";
		darkestSecret = "";
		// std::cout << "Contact created." << std::endl;
	};

	Contact::Contact(int phoneNumber, std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret) : phoneNumber(phoneNumber), firstName(firstName), lastName(lastName), nickName(nickName), darkestSecret(darkestSecret) {
		// std::cout << "Contact created2." << std::endl;
	};

	Contact::~Contact() {
		// std::cout << "Contact deleted." << std::endl;
	};

	std::string	Contact::getFirstName() const { return firstName; };
	std::string	Contact::getLastName() const { return lastName; };
	std::string	Contact::getNickname() const { return nickName; };
