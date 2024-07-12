/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:28:51 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/12 15:56:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;

	public:
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;

		void		beSigned(Bureaucrat&);

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
};

std::ostream&	operator<<(std::ostream &outputStream, const Form& form);

#endif