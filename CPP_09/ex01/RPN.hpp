/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:35:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/09 15:52:47 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>

class RPN
{
	public:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		void Calculate(const std::string input);

	private:
		std::stack<long int> stack;
};

#endif