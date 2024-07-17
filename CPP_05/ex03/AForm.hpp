/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:28:51 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/17 12:32:51 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class  AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;

	public:
		AForm();
		AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;

		void				beSigned(Bureaucrat&);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		//Exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &outputStream, const AForm& form);

#endif