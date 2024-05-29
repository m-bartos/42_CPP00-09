/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/29 13:35:24 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNumber) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = intNumber << FRACTIONALBITS;
}

Fixed::Fixed(const float floatNumber) {
	std::cout << "Float constructor called" << std::endl;
	// 1. possibility - rounding result float to integer
	fixedPointValue = roundf(floatNumber * (float) (1 << FRACTIONALBITS));
	// 2. possibility - casting (without rounding)
	// fixedPointValue = (int) (floatNumber * (float) (1 << FRACTIONALBITS));
}

Fixed::Fixed(const Fixed& oldObj) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = oldObj.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& oldObj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oldObj)
		fixedPointValue = oldObj.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	float floatNumber;

	floatNumber = (float)fixedPointValue / (float) (1 << FRACTIONALBITS);
	return (floatNumber);
}

int	Fixed::toInt (void) const {
	return (fixedPointValue >> FRACTIONALBITS);
}

std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb)
{
	outputStream << fixedNb.toFloat();
	return (outputStream);
}
