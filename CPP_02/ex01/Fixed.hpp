/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:35 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/13 12:39:26 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class	Fixed {

public:
	Fixed();
	// A copy constructor is used to initialize a previously uninitialized object from some other object's data.
	Fixed(const int intNumber);
	Fixed(const float floatNumber);
	Fixed(const Fixed&);
	// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
	Fixed& operator=(const Fixed&);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

private:
	int fixedPointValue;
	static const int FRACTIONALBITS = 8;
	
};

std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb);