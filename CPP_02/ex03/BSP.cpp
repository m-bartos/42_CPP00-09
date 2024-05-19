/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:34:24 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/19 18:28:46 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSP.hpp"

Fixed crossSectionOrientation(Point const &pointA, Point const &pointB, Point const &pointToCheck) {
	Fixed dx1 = pointToCheck.getX() - pointB.getX();
	Fixed dy1 = pointToCheck.getY() - pointB.getY();
	Fixed dx2 = pointA.getX() - pointB.getX();
	Fixed dy2 = pointA.getY() - pointB.getY();

	Fixed test((dx1 * dy2) - (dx2 * dy1));

	return (test);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed signAB;
	Fixed signBC;
	Fixed signCA;

	signAB = crossSectionOrientation(a, b, point);
	signBC = crossSectionOrientation(b, c, point);
	signCA = crossSectionOrientation(c, a, point);

	if (signAB >= 0 && signBC >= 0 && signCA >= 0)
		return (true);
	else if (signAB <= 0 && signBC <= 0 && signCA <= 0)
		return (true);
	else
		return (false);
}
