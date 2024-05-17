/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:35 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/17 11:33:39 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class	Fixed {

public:
	Fixed();
	Fixed(const int intNumber);
	Fixed(const float floatNumber);
	// A copy constructor is used to initialize a previously uninitialized object from some other object's data.
	Fixed(const Fixed&);
	// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
	Fixed& operator=(const Fixed&);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	bool	operator>(const Fixed &numB) const;
	bool	operator<(const Fixed &numB) const;
	bool	operator>=(const Fixed &numB) const;
	bool	operator<=(const Fixed &numB) const;
	bool	operator==(const Fixed &numB) const;
	bool	operator!=(const Fixed &numB) const;
	Fixed	operator+(const Fixed &numB) const;
	Fixed	operator-(const Fixed &numB) const;
	Fixed	operator*(const Fixed &numB) const;
	Fixed	operator/(const Fixed &numB) const;
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	static Fixed&	min(Fixed &numA, Fixed &numB);
	static const Fixed&	min(const Fixed &numA, const Fixed &numB);
	static Fixed&	max(Fixed &numA, Fixed &numB);
	static const Fixed&	max(const Fixed &numA, const Fixed &numB);

private:
	int fixedPointValue;
	static const int FRACTIONALBITS = 8;
	
};

std::ostream& operator<<(std::ostream &outputStream, const Fixed &fixedNb);