/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:16:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/21 15:54:10 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>

class PmergeMe 
{
	public:
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
	

		std::vector<std::pair<unsigned int, unsigned int> > pairs;
		std::vector<unsigned int> numbers;
		std::vector<unsigned int> JacobsthanSequence;
};

#endif