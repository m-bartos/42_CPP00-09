/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:05:12 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/17 13:05:23 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		AForm* makeForm(const std::string formName, const std::string formTarget);
		static AForm* createPresidentialPardonForm(const std::string target);
		static AForm* createRobotomyRequestForm(const std::string target);
		static AForm* createShrubberyCreationForm(const std::string target);

		class UnknownForm : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif