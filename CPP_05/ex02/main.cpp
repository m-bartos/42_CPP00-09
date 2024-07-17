/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:30:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/17 13:42:26 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << "------------------" << std::endl;
		try
		{
			Bureaucrat plebAli = Bureaucrat("Ali", 1);
			ShrubberyCreationForm form1 = ShrubberyCreationForm("target");

			std::cout << plebAli << std::endl;
			std::cout << form1 << std::endl;

			plebAli.signForm(form1);
			std::cout << form1 << std::endl;
			plebAli.executeForm(form1);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	{
		std::cout << "------------------" << std::endl;
		try
		{
			Bureaucrat plebAli = Bureaucrat("Ali", 26);
			RobotomyRequestForm form1 = RobotomyRequestForm("target123");

			std::cout << plebAli << std::endl;
			std::cout << form1 << std::endl;

			plebAli.signForm(form1);
			std::cout << form1 << std::endl;
			for (int i = 0; i < 10; i++)
				plebAli.executeForm(form1);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	{
		std::cout << "------------------" << std::endl;
		try
		{
			Bureaucrat plebAli = Bureaucrat("Ali", 6);
			PresidentialPardonForm form1 = PresidentialPardonForm("targetPresident");

			std::cout << plebAli << std::endl;
			std::cout << form1 << std::endl;

			plebAli.signForm(form1);
			std::cout << form1 << std::endl;
			plebAli.executeForm(form1);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	return (0);
}