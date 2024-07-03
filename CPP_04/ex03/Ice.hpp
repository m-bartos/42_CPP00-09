/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:29 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/03 14:07:48 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public Amateria {

	public:
		Ice();
		Ice(const Ice&);
		Ice& operator=(const Ice&);
		Ice(std::string const & type);
		~Ice();

		void use(ICharacter& target);
}

#endif