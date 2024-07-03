/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:03:25 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 11:07:41 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat&);
	WrongCat& operator=(const WrongCat&);
	~WrongCat();

	void makeSound() const;
};

#endif