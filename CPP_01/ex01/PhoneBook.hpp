/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:30 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/20 15:03:43 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {

public:
	
	PhoneBook();
	~PhoneBook();

private:

	int nContants;
};

class Contact {

public:
	
	// Contact();
	Contact(int phoneNumber, std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret);
	~Contact();

private:
	int phoneNumber;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
};


#endif