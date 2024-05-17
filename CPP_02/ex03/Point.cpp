/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:39:39 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/17 12:52:54 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
	Fixed x = Fixed(0);
	Fixed y = Fixed(0);
}

Point::Point(const Point& oldPoint) {
	x = oldPoint.x;
	y = oldPoint.y;
}

Point::Point(const float newX, const float newY) : x(newX), y(newY) {}

Point& Point::operator=(const Point& oldPoint) {
	if (this != &oldPoint)
	{
		x = oldPoint.x;
		y = oldPoint.y;
	}
	return (*this);
}

Point::~Point() {}