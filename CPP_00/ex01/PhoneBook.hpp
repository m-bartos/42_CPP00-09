/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:30 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 21:23:15 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	void searchContact() const;
	void addContact(Contact newContact);


private:
	Contact	contacts[8];
	int		contactCount;
	int		oldestContact;
	std::string truncateString(const std::string& str) const;
};

#endif