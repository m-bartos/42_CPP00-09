/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:18:52 by mbartos           #+#    #+#             */
/*   Updated: 2024/02/21 21:03:08 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {

public:
	
	Contact();
	Contact(long long phoneNumber, std::string firstName, std::string lastName, std::string nickName, std::string darkestSecret);
	~Contact();
	void displayContact() const;
	long long getPhoneNumber() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getDarkestSecret() const;

private:
	long long phoneNumber;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;

};

#endif