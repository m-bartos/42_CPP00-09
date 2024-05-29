/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:34 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/29 13:45:41 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int intNumber) {
	fixedPointValue = intNumber << FRACTIONALBITS;
}

Fixed::Fixed(const float floatNumber) {
	// 1. possibility - rounding result float to integer
	fixedPointValue = roundf(floatNumber * (float) (1 << FRACTIONALBITS));
	// 2. possibility - casting (without rounding)
	// fixedPointValue = (int) (floatNumber * (float) (1 << FRACTIONALBITS));
}

Fixed::Fixed(const Fixed& oldObj) {
	fixedPointValue = oldObj.fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& oldObj) {
	if (this != &oldObj)
		fixedPointValue = oldObj.getRawBits();
	return (*this);
}


Fixed::~Fixed() {}

int	Fixed::getRawBits() const {
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

bool	Fixed::operator>(const Fixed &numB) const {
	return (this->getRawBits() > numB.getRawBits());
}

bool	Fixed::operator<(const Fixed &numB) const {
	return (this->getRawBits() < numB.getRawBits());
}

bool	Fixed::operator>=(const Fixed &numB) const {
	return (this->getRawBits() >= numB.getRawBits());
}

bool	Fixed::operator<=(const Fixed &numB) const {
	return (this->getRawBits() <= numB.getRawBits());
}

bool	Fixed::operator==(const Fixed &numB) const {
	return (this->getRawBits() == numB.getRawBits());
}

bool	Fixed::operator!=(const Fixed &numB) const {
	return (this->getRawBits() != numB.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &numB) const {
	Fixed temp;

	temp.setRawBits((this->getRawBits() + numB.getRawBits()));
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &numB) const {
	Fixed temp;

	temp.setRawBits((this->getRawBits() - numB.getRawBits()));
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &numB) const {
	Fixed temp;
	
	temp.setRawBits((long long) this->getRawBits() * (long long) numB.getRawBits() >> FRACTIONALBITS);
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &numB) const {
	Fixed temp;
	
	temp.setRawBits(this->getRawBits() / numB.getRawBits() << FRACTIONALBITS);
	return (temp);
}

/*
It will increase the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
*/
Fixed&	Fixed::operator++() {
	fixedPointValue++;
	return (*this);
}

/*
It will decrease the fixed-point value from the smallest representable ϵ such as 1 - ϵ < 1.
*/
Fixed&	Fixed::operator--()
{
	fixedPointValue--;
	return (*this);
}

/*
There is one problem with deﬁning both the preﬁx and postﬁx operators: Normal
overloading cannot distinguish between these operators. The preﬁx and postﬁx
versions use the same symbol, meaning that the overloaded versions of these oper-
ators have the same name. They also have the same number and type of operands.

To solve this problem, the postﬁx versions take an extra (unused) parameter of
type int. When we use a postﬁx operator, the compiler supplies 0 as the argument
for this parameter. Although the postﬁx function can use this extra parameter,
it usually should not. That parameter is not needed for the work normally per-
formed by a postﬁx operator. Its sole purpose is to distinguish a postﬁx function
from the preﬁx version.

The postfix versions have to remember the current state of the object before incre-
menting the object:
*/
Fixed	Fixed::operator++(int) {
	Fixed oldFixed = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (oldFixed);
}

Fixed	Fixed::operator--(int) {
	Fixed oldFixed = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (oldFixed);
}

Fixed&	Fixed::min(Fixed &numA, Fixed &numB) {
	if (numA <= numB)
		return (numA);
	return (numB);
}

const Fixed&	Fixed::min(const Fixed &numA, const Fixed &numB) {
	if (numA <= numB)
		return (numA);
	return (numB);
	
}

Fixed&	Fixed::max(Fixed &numA, Fixed &numB) {
	if (numA >= numB)
		return (numA);
	return (numB);
}

const Fixed&	Fixed::max(const Fixed &numA, const Fixed &numB) {
	if (numA >= numB)
		return (numA);
	return (numB);
	
}

std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb)
{
	outputStream << fixedNb.toFloat();
	return (outputStream);
}
