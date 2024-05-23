/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:26:11 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/19 18:27:19 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "BSP.hpp"

#include <iostream>

int main( void ) {
	const Point	a(0.,0.);
	const Point	b(0.,10.);
	const Point c(10.,0.);
	const Point P1(0,0);
	const Point P2(5,5);
	const Point P3(9,10);
	const Point P4(-5,5);
	const Point P5(1,1);

	std::cout << "P1 inside triangle (different deffinitions of triangle):" << std::endl;
	std::cout << (bsp(a, c, b, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(a, b, c, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(c, a, b, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(c, b, a, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(b, c, a, P1) ? "in" : "out") << std::endl;
	std::cout << (bsp(b, a, c, P1) ? "in" : "out") << std::endl;
	std::cout << std::endl;

	std::cout << "P2, P3, P4, P5 inside triangle:" << std::endl;
	std::cout << "P2: " << (bsp(a, b, c, P2) ? "in" : "out") << std::endl;
	std::cout << "P3: " << (bsp(a, b, c, P3) ? "in" : "out") << std::endl;
	std::cout << "P4: " << (bsp(a, b, c, P4) ? "in" : "out") << std::endl;
	std::cout << "P5: " << (bsp(a, b, c, P5) ? "in" : "out") << std::endl;

	return (0);
}