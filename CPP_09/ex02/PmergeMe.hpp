/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/28 15:12:22 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <cstdlib>

#include "TypeName.hpp"

template <typename NumberContainer, typename PairContainer>
class PmergeMe 
{
	public:
		typedef typename NumberContainer::value_type ContainerType; // type of container

		PmergeMe() {}

		PmergeMe(const PmergeMe& refObj) { *this = refObj; }

		PmergeMe& operator=(const PmergeMe& refObj) { (void) refObj; return(*this); }

		~PmergeMe() {}

		void Sort(int argc, char** argv)
		{
			clock_t startTime = clock();

			for (int i = 1; i < argc; ++i)
			{
				std::string strNumber = std::string(argv[i]);
				IsValidNumber(strNumber);
				AddNumberToContainer(strNumber);
			}
			initialNumbers = numbers;
			MakePairs();
			BuildJacobsthanSequence(pairs.size());
			SortNumbersInPairs();
			SortPairs();
			InsertHigherNumberFromPairs();
			InsertRest();
			clock_t endTime = clock();
			double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC * 1e6;
			PrintNumbersInContainer();
			std::cout << "Execution Time of " << getTypeName<NumberContainer>() << ": " << elapsedTime << " microseconds" << std::endl;
			// std::cout << std::endl;
		}

		void PrintNumbersInContainer()
		{
			typename NumberContainer::const_iterator it;

			std::cout << "Before: ";
			for (it = initialNumbers.begin(); it != initialNumbers.end(); ++it)
			{
				std::cout << std::setw(3) << std::right << *it;
				if (it != initialNumbers.end() - 1)
					std::cout << ", ";
			}
			std::cout << std::endl;

			std::cout << "Before: ";
			for (it = numbers.begin(); it != numbers.end(); ++it)
			{
				std::cout << std::setw(3) << std::right << *it;
				if (it != numbers.end() - 1)
					std::cout << ", ";
			}
			std::cout << std::endl;
		}

		void PrintNumbersInPairs()
		{
			typename PairContainer::const_iterator it;
			// std::cout << "----- Pairs printing -----" << std::endl;
			for (it = pairs.begin(); it != pairs.end(); ++it)
			{
				std::cout << "Pair: ";
				std::cout << it->first << "|";
				std::cout << it->second << std::endl;
			}
			std::cout << "--------------------------" << std::endl;
		}

		void PrintJacobsthanSequence()
		{
			typename NumberContainer::const_iterator it;

			for (it = JacobsthanSequence.begin(); it != JacobsthanSequence.end(); ++it)
				std::cout << *it << std::endl;
		}

	private:
		void IsValidNumber(std::string input)
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
				if (number == 0)
					throw std::invalid_argument("Invalid input, number is 0. Only positive unsigned ints required.");
				if (number > UINT_MAX)
					throw std::invalid_argument("Invalid input, number bigger than max unsigned int.");

			}
		}

		void AddNumberToContainer(std::string input)
		{
			long int number = std::strtol(input.c_str(), NULL, 10);
			numbers.push_back(static_cast<int>(number));
		}

		void MakePairs()
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
		}

		void SortNumbersInPairs()
		{
			typename PairContainer::iterator it;

			for (it = pairs.begin(); it != pairs.end(); ++it)
			{
				if (it->first < it->second)
					std::swap(it->first, it->second);
			}
		}

		void SortPairs()
		{
			std::sort(pairs.begin(), pairs.end());
		}

		void InsertHigherNumberFromPairs()
		{
			typename PairContainer::const_iterator itPairs;
			typename PairContainer::const_iterator itPairsEnd;
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

		void InsertRest()
		{
			typename NumberContainer::iterator jacobsthanSequenceIt;

			// std::cout << pairs.size() << std::endl;
			for (jacobsthanSequenceIt = JacobsthanSequence.begin(); jacobsthanSequenceIt != JacobsthanSequence.end(); ++jacobsthanSequenceIt)
			{
				// std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				typename NumberContainer::iterator itEnd;
				typename NumberContainer::iterator itResult;
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

		int GetJacobsthanNumber(int index)
		{
			if (index == 0 || index == 1)
				return (1);
			else
				return ((2 * GetJacobsthanNumber(index - 2) + GetJacobsthanNumber(index - 1)));
		}

		void BuildJacobsthanSequence (int size)
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
	
		PairContainer pairs;
		NumberContainer initialNumbers;
		NumberContainer numbers;
		NumberContainer JacobsthanSequence;
};

#endif