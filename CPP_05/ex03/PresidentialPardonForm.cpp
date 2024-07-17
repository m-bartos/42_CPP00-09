/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:32:39 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/15 15:22:32 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	target = "";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& refObj) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = refObj.target;
	*this = refObj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& refObj)
{
	if (this != &refObj)
		this->target = refObj.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (this->getGradeRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
