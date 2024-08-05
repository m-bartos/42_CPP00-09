/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:40:06 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/05 16:43:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& refObj) { (void) refObj; };
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& refObj) { (void) refObj; return (*this); };
BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::LoadFile()
{
	std::ifstream fin("data.csv");
	if (!fin)
	{ 
		std::cerr << "Error, could not open file." << std::endl; 
		return (-1);
	}

	std::string line;
	std::string	date;
	std::string	value;
	while (std::getline(fin, line))
	{
		if (line == "date,exchange_rate")
			continue ;
		
		std::stringstream	stream(line);
		
		std::getline(stream, date, ',');
		std::getline(stream, value);
		database.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
		// break ;
	}

	fin.close();
	return (0);
}

void BitcoinExchange::print_database()
{
	for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}