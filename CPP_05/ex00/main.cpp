/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:30:57 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/12 14:07:50 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		Bureaucrat plebAli = Bureaucrat("Ali", 150);
		Bureaucrat bobTheBoss = Bureaucrat("Bob", 1);
		Bureaucrat neemand = Bureaucrat();

		std::cout << "------------------" << std::endl;
		std::cout << plebAli << std::endl;
		std::cout << bobTheBoss << std::endl;
		std::cout << neemand << std::endl;
		std::cout << "------------------" << std::endl;

		try
		{
			std::cout << "Trying to decrement '" << neemand.getName() << "'" << std::endl;
			neemand.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Trying to decrement '" << plebAli.getName() << "'" << std::endl;
			plebAli.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Trying to increment '" << bobTheBoss.getName() << "'" << std::endl;
			bobTheBoss.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "------------------" << std::endl;
		try
		{
			std::cout << "Trying to construct bureaucrat with grade 0" << std::endl;
			Bureaucrat highGrade = Bureaucrat("Boss", 0);
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	{
		std::cout << "------------------" << std::endl;
		try
		{
			std::cout << "Trying to construct bureaucrat with grade 151" << std::endl;
			Bureaucrat highGrade = Bureaucrat("Boss", 151);
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	// OR
	{
		std::cout << "------------------" << std::endl;
		try
		{
			std::cout << "Trying to construct bureaucrat with grade 151" << std::endl;
			Bureaucrat highGrade = Bureaucrat("Boss", 151);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "------------------" << std::endl;
	}
	// {
	// 	Bureaucrat highGrade = Bureaucrat("Boss", 0);
	// }
	return (0);
}