/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/08 15:01:05 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// Pointer to member function:
	// https://public.websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
	typedef void	(Harl::*Harl_pmf_message)(void);
	Harl_pmf_message	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					(this->*funcs[0])();
					(this->*funcs[1])();
					(this->*funcs[2])();
					(this->*funcs[3])();
					break ;
				case 1:
					(this->*funcs[1])();
					(this->*funcs[2])();
					(this->*funcs[3])();
					break ;
				case 2:
					(this->*funcs[2])();
					(this->*funcs[3])();
					break ;
				case 3:
					(this->*funcs[3])();
					break ;
			}
			break ;
		}
		else if (i == 3)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!\n" << std::endl;
}
void	Harl::info(void) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}