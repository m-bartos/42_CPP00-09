/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:36:55 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 12:53:07 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

public:
	Brain();
	Brain(const Brain&);
	Brain& operator=(const Brain&);
	~Brain();

	std::string ideas[100];
};

#endif