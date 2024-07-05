/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:56:08 by mbartos           #+#    #+#             */
/*   Updated: 2024/07/05 10:11:50 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	
	private:
		AMateria	*inventory[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();
	
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const &);
};

#endif