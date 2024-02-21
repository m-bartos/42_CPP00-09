/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:20:20 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 21:02:48 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

	Contact::Contact() {
		this->phoneNumber = 0;
		this->firstName = "";
		this->lastName = "";
		this->nickName = "";
		this->darkestSecret = "";
		// std::cout << "Contact created." << std::endl;
	};

	Contact::Contact(long long phoneNumber, std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret) : phoneNumber(phoneNumber), firstName(firstName), lastName(lastName), nickName(nickName), darkestSecret(darkestSecret) {
		// std::cout << "Contact created2." << std::endl;
	};

	Contact::~Contact() {
		// std::cout << "Contact deleted." << std::endl;
	};

	long long	Contact::getPhoneNumber() const { return phoneNumber; };
	std::string	Contact::getFirstName() const { return firstName; };
	std::string	Contact::getLastName() const { return lastName; };
	std::string	Contact::getNickname() const { return nickName; };
	std::string	Contact::getDarkestSecret() const { return darkestSecret; };

	void	Contact::displayContact() const {
		std::cout << "Phone number: " << getPhoneNumber() << std::endl;
		std::cout << "First name: " << getFirstName() << std::endl;
		std::cout << "Last name: " << getLastName() << std::endl;
		std::cout << "Nickname: " << getNickname() << std::endl;
		std::cout << "Darkest secret: " << getDarkestSecret() << std::endl;
	}
