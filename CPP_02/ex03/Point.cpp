/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:39:39 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/29 14:07:55 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point& oldPoint) : x(oldPoint.getX()), y(oldPoint.getY()) {}

Point::Point(const float newX, const float newY) : x(newX), y(newY) {}

// cannot assign const variables, copy assignment operator overload is nonsense
Point& Point::operator=(const Point& oldPoint) {
	(void)oldPoint;
	return (*this);
}

Point::~Point() {}

std::ostream& operator<<(std::ostream &outputStream, const Point &point)
{
	outputStream << "(" << point.getX() << ", " << point.getY() << ")";
	return (outputStream);
}

const Fixed&	Point::getX() const { return (this->x); }

const Fixed&	Point::getY() const { return (this->y); }
