/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:24:17 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/30 16:47:29 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxNumbers(0) {};

Span::Span(unsigned int maxNums) : maxNumbers(maxNums) {};

Span::Span(const Span& refObj) : maxNumbers(refObj.maxNumbers) {};

Span& Span::operator=(const Span& refObj)
{
	maxNumbers = refObj.maxNumbers;
	return (*this);
};

Span::~Span() {};

void Span::addNumber(int newNumber)
{
	if (numbers.size() < maxNumbers)
		numbers.insert(newNumber);
};

long int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw EmptyContainer();

	long int result = labs(static_cast<long int>(*numbers.rbegin()) - static_cast<long int>(*numbers.begin()));
	return (result);
};

void Span::printElement(int element)
{
	std::cout << element << ", ";
};

void Span::printNumbers() const
{
	std::cout << "Numbers: ";
	std::for_each(numbers.begin(), numbers.end(), Span::printElement);
	std::cout << std::endl;
}

// void Span::printNumbers()
// {
// 	for_each (numbers.begin(), numbers.end(), Span::printElement<int>);
// };

const char* Span::EmptyContainer::what() const throw()
{
	return "The container is empty.";
};