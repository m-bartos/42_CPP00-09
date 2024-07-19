/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:25:22 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/19 17:11:54 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>

#include "StringUtils.hpp"

class ScalarConverter
{
	private:

		enum Type {
			ERROR = -1,
			EMPTY = 0,
			SPECIAL = 1,
			CHAR,
			INT,
			DOUBLE,
			FLOAT
		};

		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		const ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static int typeChoose(const std::string input);
		static bool isSpecial(const std::string str);
		static bool isChar(const std::string str);
		static bool isInt(const std::string str);
		static bool isFloat(const std::string str);
		static bool isDouble(const std::string str);

	public:
		static void	convert(const std::string input);

		class invalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif