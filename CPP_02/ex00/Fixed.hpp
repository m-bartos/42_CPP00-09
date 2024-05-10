/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:35 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/09 11:40:01 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed {

public:
	Fixed();
	// A copy constructor is used to initialize a previously uninitialized object from some other object's data.
	Fixed(const Fixed&);
	// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
	Fixed& operator=(const Fixed&);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	

private:
	int fixedPointValue;
	static const int FRACTIONALBITS = 8;
	
};