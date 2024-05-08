/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:05 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/08 12:30:49 by mbartos          ###   ########.fr       */
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
			(this->*funcs[i])();
	}
}

void	Harl::debug(void) {
	std::cout << "DEBUG: I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}
void	Harl::info(void) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	
}

void	Harl::error(void) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}