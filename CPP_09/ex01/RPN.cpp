/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:35:36 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/09 15:53:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& refObj) { *this = refObj; }

RPN& RPN::operator=(const RPN& refObj) { (void) refObj; return(*this); }

RPN::~RPN() {}

void RPN::Calculate(const std::string input)
{
	std::string::const_iterator it;
	for (it = input.begin(); it != input.end(); ++it)
	{
		char c = *it;

		if (isspace(c))
			continue ;
		if (isdigit(c)) 
		{
			stack.push(c);
			continue;
		}
		else
		{
			// switch (c)
			// {
			// 	case '+':
			// 		add();
			// 		break;
			// 	case '-':
			// 		subtract();
			// 		break;
			// 	case '*':
			// 		multiply();
			// 		break;
			// 	case '/':
			// 		divide();
			// 		break;
			// 	default:
			// 		throw std::runtime_error("Unknown character encountered: " + std::string(1, c));
			// }
		}
	}
}