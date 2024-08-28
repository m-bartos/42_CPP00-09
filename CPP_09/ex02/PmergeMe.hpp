/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/28 12:31:05 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>

template <typename T>
std::string getTypeName() {
    return "Unknown type";
}

// Specializations for known types
template <>
std::string getTypeName<std::vector<unsigned int> >() {
    return "std::vector<unsigned int>";
}

template <>
std::string getTypeName<std::deque<unsigned int> >() {
    return "std::deque<unsigned int>";
}

template <typename Container, typename PairContainer>
class PmergeMe 
{
	public:
		typedef typename Container::value_type ContainerType; // type of container

		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		void Sort(int argc, char** argv);
		void PrintNumbersInContainer();
		void PrintNumbersInPairs();
		void PrintJacobsthanSequence();

	private:
		void IsValidNumber(std::string input);
		void AddNumberToContainer(std::string input);
		void MakePairs();
		void SortNumbersInPairs();
		void SortPairs();
		void InsertHigherNumberFromPairs();
		void InsertRest();

		int GetJacobsthanNumber(int index);
		void BuildJacobsthanSequence (int size);
	
		PairContainer pairs;
		Container initialNumbers;
		Container numbers;
		Container JacobsthanSequence;
};

#endif