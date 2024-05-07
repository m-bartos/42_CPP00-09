/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:49:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 10:06:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "ADRESSES:" << std::endl;
	std::cout << std::setw(45) << "The memory address of the string variable:   " << &str << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringPTR:   " << stringPTR << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringREF:   " << &stringREF << std::endl; 

	std::cout << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout << std::setw(40) << "The value of the string variable:   " << str << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringPTR:   " << *stringPTR << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringREF:   " << stringREF << std::endl;

	return (0);
}