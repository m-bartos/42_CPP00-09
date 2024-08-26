/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/26 14:32:01 by mbartos          ###   ########.fr       */
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
	{
		std::cout << std::setw(3) << std::right << *it;
		if (it != numbers.end() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
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

	for ( ; i < numbers.size() - 1; i = i + 2)
	{
		unsigned int a = numbers[i];
		unsigned int b = numbers[i+1];
		pairs.push_back(std::make_pair(a, b));
	}
	if (numbers.size() % 2 != 0)
		pairs.push_back(std::make_pair(UINT_MAX, numbers[i]));
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
	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator itPairs;
	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator itPairsEnd;
	bool odd = false;

	if (numbers.size() % 2 != 0)
		odd = true;
	numbers.clear();
	if (odd)
		itPairsEnd = pairs.end() - 1;
	else
		itPairsEnd = pairs.end();
	for (itPairs = pairs.begin(); itPairs != itPairsEnd; ++itPairs)
		numbers.push_back(itPairs->first);
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
}

void PmergeMe::InsertRest()
{
	std::vector<unsigned int>::iterator jacobsthanSequenceIt;

	// std::cout << pairs.size() << std::endl;
	for (jacobsthanSequenceIt = JacobsthanSequence.begin(); jacobsthanSequenceIt != JacobsthanSequence.end(); ++jacobsthanSequenceIt)
	{
		// std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::vector<unsigned int>::iterator itEnd;
		std::vector<unsigned int>::iterator itResult;
		itEnd = std::find(numbers.begin(), numbers.end(), pairs[*jacobsthanSequenceIt].first);
		itResult = lower_bound(numbers.begin(), itEnd, pairs[*jacobsthanSequenceIt].second);
		// std::cout << "Number to be inserted from pair[" << (*jacobsthanSequenceIt) + 1 << "] = " << pairs[*jacobsthanSequenceIt].second << ". Searching in <" << *(numbers.begin()) << ", " << *(itEnd) << ">" << std::endl;
		// std::cout << "The number will be inserted before value = " << *itResult << std::endl;
		// std::cout << "~~~~~~~~~~~~~~~ Before insertation ~~~~~~~~~~~~~~~~~" << std::endl;
		// PrintNumbersInContainer();
		numbers.insert(itResult, pairs[*jacobsthanSequenceIt].second);
		// std::cout << "~~~~~~~~~~~~~~~ After insertation ~~~~~~~~~~~~~~~~~~~" << std::endl;
		// PrintNumbersInContainer();
		// std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		// std::cout << std::endl;
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
	std::cout << "Before: ";
	PrintNumbersInContainer();
	// std::cout << std::endl;


	// std::cout << "-----------" << std::endl;
	MakePairs();
	// std::cout << "Pairs made: " << std::endl;
	// PrintNumbersInPairs();
	// return;
	BuildJacobsthanSequence(pairs.size());
	// std::cout << "JacobSeq: " << std::endl;
	// PrintJacobsthanSequence();
	// std::cout << "Numbers in pairs sorted: " << std::endl;
	SortNumbersInPairs();
	// PrintNumbersInPairs();
	SortPairs();
	// std::cout << "Pairs sorted: " << std::endl;
	// PrintNumbersInPairs();
	InsertHigherNumberFromPairs();
	// PrintNumbersInPairs();
	InsertRest();
	std::cout << "After:  ";
	PrintNumbersInContainer();
	// std::cout << std::endl;
}
