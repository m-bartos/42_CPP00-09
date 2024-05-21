/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:30 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/21 13:26:50 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

# define BOLD "\e[0;1m"
# define RESET "\e[0m"

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	void searchContact() const;
	int	tryToAddContact();
	static int	IsEofOrFail();

private:
	Contact	contacts[8];
	int		contactCount;
	int		oldestContact;
	std::string truncateString(const std::string& str) const;
	void addContact(Contact newContact);
};

#endif