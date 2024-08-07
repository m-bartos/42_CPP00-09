/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:40:06 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/07 19:31:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->LoadDaysInMonths();
	this->fin = NULL;
	this->dataCsv = NULL;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& refObj) 
{
	(void) refObj;
	this->LoadDaysInMonths();
	this->fin = NULL;
	this->dataCsv = NULL;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& refObj) { (void) refObj; return (*this); };

BitcoinExchange::~BitcoinExchange()
{
	if (this->fin != NULL && this->fin->is_open())
		this->fin->close();
	if (this->dataCsv != NULL && this->dataCsv->is_open())
		this->dataCsv->close();
	delete this->dataCsv;
	delete this->fin;
};

// this is not good - leaking when throwing exception
// should do it in LoadInput and LoadDB funcs and delete this one
std::ifstream* BitcoinExchange::LoadFile(const std::string filename)
{
	std::ifstream* fin1 = new std::ifstream(filename.c_str());
	if (!fin1->is_open())
	{
		throw std::runtime_error("Cannot open file: " + filename); // problem!
	}
	return (fin1);
}

int BitcoinExchange::LoadDB()
{
	this->dataCsv = LoadFile("data.csv");
	if (!this->dataCsv)
	{ 
		std::cerr << "Error, could not open DB file." << std::endl; 
		return (-1); // exit?
	}

	std::string line;
	std::string	date;
	std::string	value;
	while (std::getline(*(this->dataCsv), line))
	{
		if (line == "date,exchange_rate")
			continue ;

		std::stringstream	stream(line);

		std::getline(stream, date, ',');
		std::getline(stream, value);
		database.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
	}
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
	return line.substr(start, end - start + 1);
}

void BitcoinExchange::LoadDaysInMonths()
{
	daysInMonths.insert(std::make_pair("01", 31));
	daysInMonths.insert(std::make_pair("02", 28));
	daysInMonths.insert(std::make_pair("03", 31));
	daysInMonths.insert(std::make_pair("04", 30));
	daysInMonths.insert(std::make_pair("05", 31));
	daysInMonths.insert(std::make_pair("06", 30));
	daysInMonths.insert(std::make_pair("07", 31));
	daysInMonths.insert(std::make_pair("08", 31));
	daysInMonths.insert(std::make_pair("09", 30));
	daysInMonths.insert(std::make_pair("10", 31));
	daysInMonths.insert(std::make_pair("11", 30));
	daysInMonths.insert(std::make_pair("12", 31));
}

int BitcoinExchange::CheckHeader(std::ifstream& fin)
{
	std::string line;
	std::getline(fin, line);

	std::string date;
	std::string value;
	std::stringstream stream(line);

	std::getline(stream, date, '|');
	date = trim(date);
	std::getline(stream, value);
	value = trim (value);
	if (date != "date" || value != "value")
	{
		std::cout << "Header is missing. Add it to the file in format \"date | value\"" << std::endl;
		return (0);
	}
	return (1);
}

int BitcoinExchange::CheckLine(std::string line)
{
	if (line.size() < 12 || line.find_last_of("|") != line.find_first_of("|") || line.find_first_of("|") == std::string::npos)
	{
		std::cout << "Error: Invalid line." << std::endl;
		return (0);
	}
	return (1);
}

int BitcoinExchange::CheckDate(std::string date)
{
	if (date.size() != 10)
	{
		std::cout << "Error: Invalid date." << std::endl;
		return (0);
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: Invalid date." << std::endl;
		return (0);
	}
	if (date < "2009-01-02")
	{
		std::cout << "Error: Invalid date." << std::endl;
		return (0);
	}
	int year = std::atoi(date.substr(0,4).c_str());
	std::string month = date.substr(5, 2);
	int day = std::atoi(date.substr(8, 2).c_str());
	// std::cout << year << "-" << month << std::endl;
	std::map<std::string, int>::iterator it = daysInMonths.find(month);
	// leap year?
	if (month == "02" && it != daysInMonths.end())
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			// is leap year
			if (day > (it->second + 1))
			{
				std::cout << "Error: Invalid date." << std::endl;
				return (0);
			}
		}
		else
		{
			// is not leap year;
			if (day > (it->second))
			{
				std::cout << "Error: Invalid date." << std::endl;
				return (0);
			}
		}
	}
	else if (it == daysInMonths.end() || day > it->second)
	{
		std::cout << "Error: Invalid date." << std::endl;
		return (0);
	}

	return (1);
}

int BitcoinExchange::CheckValue(std::string value)
{
	if (value.find_last_of(".") != value.find_first_of("."))
	{
		std::cout << "Error: Invalid value. Multiple dots." << std::endl;
		return (0);
	}
	double	amount = strtod(value.c_str(), NULL);
	if (amount < 0 || amount > 1000)
	{
		std::cout << "Error: Number not in <0, 1000> range." << std::endl;
		return (0);
	}
	return (1);
}

void BitcoinExchange::FindAndPrint(std::string date, std::string value)
{
	double	amount = strtod(value.c_str(), NULL);
	std::map<std::string, double>::const_iterator it = this->database.find(date);
	if (it == this->database.end())
	{
		it = this->database.upper_bound(date);
		if (it != this->database.begin())
			it--;
		else
			std::cout << "Date not found." << std::endl;
	}
	std::cout << date << " => " << amount << " = " << it->second * amount << std::endl;

}

int BitcoinExchange::LoadInput(const std::string inputFileName)
{
	this->fin = this->LoadFile(inputFileName);
	if (this->CheckHeader(*(this->fin)) == 0)
		return (-1); // exit?

	std::string line;
	while (std::getline(*(this->fin), line))
	{
		if (this->CheckLine(line) == 0)
			continue ;

		std::stringstream stream(line);

		std::string date;
		std::getline(stream, date, '|');
		date = trim(date);
		if (this->CheckDate(date) == 0)
			continue ;

		std::string value;
		std::getline(stream, value);
		value = trim(value);
		if(this->CheckValue(value) == 0)
			continue ;

		this->FindAndPrint(date, value);
	}
	return (0);
}