/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:31:04 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/12 12:36:45 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& refObj) : grade(refObj.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& refObj)
{
	grade = refObj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

void	Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

int Bureaucrat::getGrade()
{
	return (grade);
}

const std::string Bureaucrat::getName() 
{
	return (name);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high! 1 is maximum-ultra-high king of everything grade!");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low! 150 is minimum grade for the lowest pleb bureaucrat!");
};