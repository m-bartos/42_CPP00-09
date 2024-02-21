/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:33 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 21:12:14 by mbartos          ###   ########.fr       */
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

    void PhoneBook::searchContact() const {
        std::cout << "|" 
				  << std::setw(10) << std::right << "Index" << "|"
                  << std::setw(10) << std::right << "First Name" << "|"
                  << std::setw(10) << std::right << "Last Name" << "|"
                  << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
        
        for (size_t i = 0; i < contactCount; ++i)
		{
            std::cout << "|" 
					  << std::setw(10) << std::right << i << "|"
                      << std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "|"
                      << std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "|"
                      << std::setw(10) << std::right << truncateString(contacts[i].getNickname()) << "|" << std::endl;
        }
		size_t index;
		bool validIndex = false;
		while (!validIndex)
		{
			std::cout << "Enter index of contact to display: " << std::endl;
			std::cin >> index;
			if (index >= 0 && index < contactCount)
				validIndex = true;
			else
				std::cout << "Invalid index. Please try again." << std::endl;
		}

		contacts[index].displayContact();
    }

    std::string PhoneBook::truncateString(const std::string& str) const {
        if (str.length() > 10)
            return (str.substr(0, 9) + ".");
        return (str);
    }

	void PhoneBook::addContact(Contact newContact) {
		if (this->contactCount < 8)
		{
			this->contacts[this->contactCount] = newContact;
			this->contactCount++;
		}
		else
		{
			this->contacts[this->oldestContact] = newContact;
			this->oldestContact = (this->oldestContact + 1) % 8;
		}
	};
