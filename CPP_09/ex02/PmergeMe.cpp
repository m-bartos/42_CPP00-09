/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/12 18:06:40 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& refObj) { *this = refObj; }
PmergeMe& PmergeMe::operator=(const PmergeMe& refObj) { (void) refObj; return(*this); }
PmergeMe::~PmergeMe() {}

void PmergeMe::IsValidNumber(std::string input)
{
	size_t i = 0;

	if (input[i] == '+')
		i++;

	for( ; i < input.size(); ++i)
	{
		if (i > 11)
			throw std::invalid_argument("Invalid input, number bigger than max unsigned int.");
		// MAKE IT BETTER!!
		// std::cout << i << "/" << input.size() << " = " << input[i] << std::endl;
		if (!isdigit(input[i]))
			throw std::invalid_argument("Invalid input.");
		long int number = std::strtol(input.c_str(), NULL, 10);
		if (number > UINT_MAX)
			throw std::invalid_argument("Invalid input, number bigger than max unsigned int.");

	}
}

void PmergeMe::AddNumberToContainer(std::string input)
{
	long int number = std::strtol(input.c_str(), NULL, 10);
	numbers.push_back(static_cast<int>(number));
}

void PmergeMe::PrintNumbersInContainer()
{
	for (std::vector<unsigned int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
		std::cout << *it << std::endl;
}

void PmergeMe::PrintNumbersInPairs()
{
	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::cout << "Pair: ";
		std::cout << it->first << "|";
		std::cout << it->second << std::endl;
	}
}

void PmergeMe::MakePairs()
{
	size_t i = 0;

	if (numbers.size() % 2 == 0)
	{
		for ( ; i < numbers.size(); i = i + 2)
		{
			unsigned int a = numbers[i];
			unsigned int b = numbers[i+1];
			pairs.push_back(std::make_pair(a, b));
		}
	}
}

void PmergeMe::Sort(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string strNumber = std::string(argv[i]);
		IsValidNumber(strNumber);
		AddNumberToContainer(strNumber);
	}
	MakePairs();
	//sortPairs();
	// insert lower number from pairs to new vector
	// insert the higher number by the algorithm
}
