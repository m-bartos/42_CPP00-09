/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:32 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/30 16:45:11 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>

class Span 
{
	public:
		Span();
		Span(unsigned int maxNums);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();

		void addNumber(int newNumber);
		long int longestSpan();
		void printNumbers() const;

	class EmptyContainer : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:
		static void printElement(int element);
		unsigned int		maxNumbers;
		std::multiset<int>	numbers;
};

#endif