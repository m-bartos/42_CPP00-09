/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:59:02 by mbartos           #+#    #+#             */
/*   Updated: 2024/06/07 11:01:50 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal&);
	WrongAnimal& operator=(const WrongAnimal&);
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;

protected:
	std::string type;
};


#endif