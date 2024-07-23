/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:29:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/23 09:18:09 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& refObj) { *this = refObj; }
const ScalarConverter& ScalarConverter::operator=(const ScalarConverter& refObj) { (void)refObj; return (*this); };
ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(const std::string str)
{
	if (!isdigit(static_cast<unsigned char>(str[0])) && str.size() == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isSpecial(const std::string str)
{
	if (str == "-inff" || str == "+inff" ||
		str == "-inf" || str == "+inf" ||
		str == "nan" || str == "nanf")
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string str)
{
	std::string::size_type i;

	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	for (; i < str.size(); i++)
	{
		if (!isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string str)
{
	std::string::size_type i;

	if (str.size() < 2)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	for(; i < str.size() - 1; i++)
	{
		if (!isdigit(static_cast<unsigned char>(str[i])) && str[i] != '.')
			return (false);
	}
	if (str[str.size() - 1] == 'f' && str.find_first_of("f") == str.find_last_of("f")
			&& str.find_first_of(".") == str.find_last_of(".") && str.find_first_of(".") != std::string::npos)
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string str)
{
	std::string::size_type i;

	if (str.size() < 2)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	if (StringUtils::digitsAndOneDotOnly(&str[i]))
		return (true);
	return (false);
}

int	ScalarConverter::typeChoose(const std::string input)
{
	if (input.empty())
		return (EMPTY);
	else if (isSpecial(input))
		return (SPECIAL);
	else if(isChar(input))
		return (CHAR);
	else if(isInt(input))
		return (INT);
	else if(isFloat(input))
		return (FLOAT);
	else if(isDouble(input))
		return (DOUBLE);
	return (ERROR);
}

const char *ScalarConverter::invalidInputException::what(void) const throw() 
{
	return ("Invalid input.");
}

void	ScalarConverter::convert(const std::string input)
{
	int type;

	type = typeChoose(input);
	std::cout << "Input: |" << input << "|, type: " << type << std::endl;
	if (type == ERROR || type == EMPTY)
		throw invalidInputException();
}