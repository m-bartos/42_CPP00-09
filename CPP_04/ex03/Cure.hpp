/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 14:07:48 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public Amateria {

	public:
		Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure&);
		Cure(std::string const & type);
		~Cure();

		void use(ICharacter& target);
}

#endif