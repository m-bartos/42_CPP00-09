/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:40:06 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/06 16:15:09 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& refObj) { (void) refObj; };
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& refObj) { (void) refObj; return (*this); };
BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::LoadDB()
{
	std::ifstream fin("data.csv");
	if (!fin)
	{ 
		std::cerr << "Error, could not open DB file." << std::endl; 
		return (-1); // exit?
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

void BitcoinExchange::printDatabase()
{
	for (std::map<std::string, double>::const_iterator it = database.begin(); it != database.end(); it++)
	{
		std::cout << "|" << it->first << "|" << it->second << "|" << std::endl;
	}
}

std::string trim(const std::string& line)
{
	const char* WhiteSpace = " \t\v\r\n";
	std::size_t start = line.find_first_not_of(WhiteSpace);
	std::size_t end = line.find_last_not_of(WhiteSpace);
	return start == end ? std::string() : line.substr(start, end - start + 1);
}

int BitcoinExchange::LoadInput(char *inputFileName)
{
	std::ifstream fin(inputFileName);
	if (!fin)
	{ 
		std::cerr << "Error, could not open input file." << std::endl; 
		return (-1); // exit?
	}


	// header check
	{
	std::string line;
	std::string date;
	std::string value;
	std::getline(fin, line);

	std::stringstream stream(line);
	
	std::getline(stream, date, '|');
	date = trim(date);
	std::getline(stream, value);
	value = trim (value);
	if (date == "date" && value == "value")
		std::cout << "Header found" << std::endl;
	else
	{
		std::cout << "Header is missing. Add it to the file in format \"date | value\"" << std::endl;
		return (-1);
	}
	}

	std::string line;
	// load and evaluate the lines
	while (std::getline(fin, line))
	{
		// std::cout << "In while loop" << std::endl;
		// std::cout << "Line = |" << line << "|" << std::endl;
		std::string date;
		std::string value;
		std::stringstream stream(line);

		std::getline(stream, date, '|');
		date = trim(date);
		// check date format and year, month, day numbers

		std::getline(stream, value);
		// std::cout << "|" << value << "|" << std::endl;
		// value = trim(value);
		// std::cout << "|" << value << "|" << std::endl;

		// std::cout << "Date = |" << date << "|, value = |" << value << "|" << std::endl;
		double	amount = strtod(value.c_str(), NULL);
		if (amount < 0 || amount > 1000)
			std::cout << "Error: Number not in <0, 1000> range." << std::endl;
		else
		{
			std::cout << "Amount: " << amount << std::endl;
			std::cout << "Date(search): |" << date << "|" << std::endl;
			std::multimap<std::string, double>::const_iterator it = database.find(date);
			if (it == database.end())
				it = database.upper_bound(date);
			if (it != database.end() && it != database.begin())
			{
				it--;
				if (it != database.begin())
					std::cout << "Date(found): " << it->first << ", " << "price: " << it->second << ". Result = " << it->second * amount << std::endl;
				else
					std::cout << "Date not in range." << std::endl;
			}
			else
				std::cout << "Date not found." << std::endl;
		}
	}

	return (0);
}