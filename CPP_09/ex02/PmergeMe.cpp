/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/21 16:15:09 by mbartos          ###   ########.fr       */
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

void PmergeMe::PrintJacobsthanSequence()
{
	for (std::vector<unsigned int>::const_iterator it = JacobsthanSequence.begin(); it != JacobsthanSequence.end(); ++it)
		std::cout << *it << std::endl;
}

void PmergeMe::PrintNumbersInPairs()
{
	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it;
	// std::cout << "----- Pairs printing -----" << std::endl;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::cout << "Pair: ";
		std::cout << it->first << "|";
		std::cout << it->second << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
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
	// numbers.clear();
}

void PmergeMe::SortNumbersInPairs()
{
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void PmergeMe::SortPairs()
{
	std::sort(pairs.begin(), pairs.end());
}

void PmergeMe::InsertHigherNumberFromPairs()
{
	std::vector<std::pair<unsigned int, unsigned int> >::iterator itPairs;
	// std::vector<unsigned int>::iterator itNumbers;

	numbers.clear();

	// itNumbers = numbers.begin();
	// *itNumbers = 0;
	// itNumbers++;
	for (itPairs = pairs.begin(); itPairs != pairs.end(); ++itPairs)
	{
		numbers.push_back(itPairs->first);
		itPairs->first = 0;
		// *(itNumbers + 1) = 0; 
		// itNumbers += 2;
	}
}

// recursion
int PmergeMe::GetJacobsthanNumber(int index)
{
	if (index == 0 || index == 1)
		return (1);
	else
		return ((2 * GetJacobsthanNumber(index - 2) + GetJacobsthanNumber(index - 1)));
}

void PmergeMe::BuildJacobsthanSequence (int size)
{
	int i = 0;
	int num;

	while (GetJacobsthanNumber(i) < size)
	{
		num = GetJacobsthanNumber(i);
		if (i == 0)
		{
			i++;
			continue;
		}
		JacobsthanSequence.push_back(num - 1);
		num--;
		while (num > GetJacobsthanNumber(i - 1))
		{
			JacobsthanSequence.push_back(num - 1);
			num--;
		}
		i++;
	}
	while (size > GetJacobsthanNumber(i - 1))
	{
		JacobsthanSequence.push_back(size - 1);
		size--;
	}
	// JacobsthanSequence();
}

void PmergeMe::InsertRest()
{
	// insert first element from pairs and then first element from numbers
	std::vector<unsigned int> newNumbers;
	newNumbers.push_back(pairs[0].second);
	newNumbers.push_back(numbers[0]);


	numbers = newNumbers;
}

void PmergeMe::Sort(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string strNumber = std::string(argv[i]);
		IsValidNumber(strNumber);
		AddNumberToContainer(strNumber);
	}
	std::cout << "-----------" << std::endl;
	MakePairs();
	std::cout << "Pairs made: " << std::endl;
	PrintNumbersInPairs();
	BuildJacobsthanSequence(pairs.size());
	std::cout << "JacobSeq: " << std::endl;
	PrintJacobsthanSequence();
	std::cout << "Numbers in pairs sorted: " << std::endl;
	SortNumbersInPairs();
	PrintNumbersInPairs();
	std::cout << "Pairs sorted: " << std::endl;
	SortPairs();
	PrintNumbersInPairs();
	InsertHigherNumberFromPairs();
	PrintNumbersInPairs();
	InsertRest();
	// std::cout << "Jacob: " << GetJacobsthanNumber(4) << std::endl;
	// PrintNumbersInContainer();
	// insert lower number from pairs to new vector
	// insert the higher number by the algorithm
}