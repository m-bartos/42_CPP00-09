/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:33 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/21 13:36:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
	oldestContact = 0;
	// std::cout << "Phonebook created." << std::endl;
};

PhoneBook::~PhoneBook() {
	// std::cout << "Phonebook destroyed." << std::endl;
};

int	PhoneBook::searchContact() const {
	std::cout<<std::endl;
	std::cout	<< BOLD <<"|" 
				<< std::setw(10) << std::right << "Index" << "|"
				<< std::setw(10) << std::right << "First Name" << "|"
				<< std::setw(10) << std::right << "Last Name" << "|"
				<< std::setw(10) << std::right << "Nickname" << "|" << RESET << std::endl;
	for (int i = 0; i < contactCount; ++i) {
		std::cout	<< "|" 
					<< std::setw(10) << std::right << i << "|"
					<< std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "|"
					<< std::setw(10) << std::right << truncateString(contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << std::endl;

	int index;
	bool validIndex = false;
	while (!validIndex)
	{
		std::cout << "Please enter a valid index or -1 to get back to main menu: " << std::endl;
		std::cin >> index;
		if (std::cin.eof()) {
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return (1);
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.\n" << std::endl;
		}
		else if ((index >= 0 && index < contactCount) || index == -1)
			validIndex = true;
		else
			std::cout << "Invalid index.\n" << std::endl;
	}
	if (index != -1)
		contacts[index].displayContact();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (0);
}

std::string PhoneBook::truncateString(const std::string& str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::tryToAddContact() {
	std::string	phoneNumber;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	darkestSecret;

	do {
		std::cout << "Enter phone number: " << std::endl;
		std::getline(std::cin, phoneNumber);
		if (PhoneBook::IsEofOrFail())
			return (1);
		while (!Contact::isValidPhoneNumber(phoneNumber)) {
			std::cout << "Invalid input. Please enter a valid phone number: " << std::endl;
			std::getline(std::cin, phoneNumber);
			if (PhoneBook::IsEofOrFail())
				return (1);
		}
	} while (phoneNumber.empty());
	do {
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, firstName);
		if (PhoneBook::IsEofOrFail())
			return (1);
	} while (firstName.empty());
	do {
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, lastName);
		if (PhoneBook::IsEofOrFail())
			return (1);
	} while (lastName.empty());
	do {
		std::cout << "Enter nickname: " << std::endl;
		std::getline(std::cin, nickName);
		if (PhoneBook::IsEofOrFail())
			return (1);
	} while (nickName.empty());
	do {
		std::cout << "Enter darkest secret: " << std::endl;
		std::getline(std::cin, darkestSecret);
		if (PhoneBook::IsEofOrFail())
			return (1);
	} while (darkestSecret.empty());
	this->addContact(Contact(phoneNumber, firstName, lastName, nickName, darkestSecret));
	std::cout << BOLD << "\nContact added successfuly!" << RESET << std::endl;
	return (0);
}

int	PhoneBook::IsEofOrFail() {
	if (std::cin.eof() || std::cin.fail()) {
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		return (1);
	}
	return (0);
}

void	PhoneBook::addContact(Contact newContact) {
	if (this->contactCount < 8) {
		this->contacts[this->contactCount] = newContact;
		this->contactCount++;
	}
	else {
		this->contacts[this->oldestContact] = newContact;
		this->oldestContact = (this->oldestContact + 1) % 8;
	}
};
