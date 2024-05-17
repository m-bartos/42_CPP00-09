/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/17 11:45:07 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

// // Main function from subject;
// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed test (42);

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "c + b = " << c << " + " << b << " = " << c + b << std::endl;
	std::cout << "c - b = " << c << " - " << b << " = " << c - b << std::endl;
	std::cout << "c * b = " << c << " * " << b << " = " << c * b << std::endl;
	std::cout << "c / b = " << c << " / " << b << " = " << c / b << std::endl;
	std::cout << "a / c = " << a << " / " << c << " = " << a / c << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "++test (test = " << test << ") " << " => " << ++test << std::endl;
	std::cout << "test++ (test = " << test << ") " << " => " << test++ << std::endl;
	std::cout << "test = " << test << std::endl;
	std::cout << "--test (test = " << test << ") " << " => " << --test << std::endl;
	std::cout << "test-- (test = " << test << ") " << " => " << test-- << std::endl;
	std::cout << "test = " << test << std::endl;

	std::cout << std::endl;

	std::cout << "a = " << a << ", c = " << c << std::endl;
	if (a > c)
		std::cout << "a is greater than c" << std::endl;
	else
		std::cout << "a is not greater than c" << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "The min value of " << c << " and " << d << " is: ";
	std::cout << Fixed::min(c, b) << std::endl;
	std::cout << "The max value of " << c << " and " << d << " is: ";
	std::cout << Fixed::max(c, b) << std::endl;
	
	std::cout << std::endl;
	
	return (0);
}