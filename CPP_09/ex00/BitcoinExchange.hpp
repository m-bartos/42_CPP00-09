/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:35:52 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/07 09:49:04 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		int LoadDB();
		void printDatabase(); // for checking
		int LoadInput(char *inputFileName);


	private:
		void LoadDaysInMonths();
		std::map<std::string, double> database;
		std::map<std::string, int> daysInMonths;
};

std::string trim(const std::string& line);

#endif