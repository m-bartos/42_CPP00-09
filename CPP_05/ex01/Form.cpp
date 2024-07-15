/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:32:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/15 11:07:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : name(""), isSigned(false), gradeRequiredToSign(MINIMUM_GRADE), gradeRequiredToExecute(MINIMUM_GRADE)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), 
		gradeRequiredToSign((gradeToSign > MINIMUM_GRADE) ? throw Form::GradeTooLowException() : (gradeToSign < MAXIMUM_GRADE) ? throw Form::GradeTooHighException() : gradeToSign),
		gradeRequiredToExecute((gradeToExecute > MINIMUM_GRADE) ? throw Form::GradeTooLowException() : (gradeToExecute < MAXIMUM_GRADE) ? throw Form::GradeTooHighException() : gradeToExecute)
{}

Form::Form(const Form& refObj) : name(refObj.name), isSigned(refObj.isSigned), gradeRequiredToSign(refObj.gradeRequiredToSign), gradeRequiredToExecute(refObj.gradeRequiredToExecute)
{}

// Does not make so much sense because of const variables
Form& Form::operator=(const Form& refObj)
{
	isSigned = refObj.isSigned;
	return(*this);
}

Form::~Form() {}

std::string	Form::getName() const {return (name);}
bool	Form::getIsSigned() const {return (isSigned);}
int	Form::getGradeRequiredToSign() const {return (gradeRequiredToSign);}
int	Form::getGradeRequiredToExecute() const {return (gradeRequiredToExecute);}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->getGradeRequiredToSign() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}


std::ostream&	operator<<(std::ostream &outputStream, const Form& form)
{
	outputStream << "Form: '" << form.getName();
	outputStream << "', grade required to sign: " << form.getGradeRequiredToSign();
	outputStream << ", grade required to execute: " << form.getGradeRequiredToExecute();
	outputStream << ", signed: " << form.getIsSigned() << ".";
	return(outputStream);
}