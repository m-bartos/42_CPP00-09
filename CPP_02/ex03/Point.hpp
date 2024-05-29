/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:41:10 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/29 14:04:53 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:
	Point();
	// Copy constructor
	Point(const Point&);
	Point(const float newX, const float newY);
	// An assignment operator is used to replace the data of a previously initialized object with some other object's data.
	Point& operator=(const Point&);
	// Point	operator+(const Point &pointB) const;
	~Point();
	const Fixed& getX() const;
	const Fixed& getY() const;
	// static Fixed pointDistance(const Point &pointA, const Point &pointB);

	private:
	Fixed const x;
	Fixed const y;
};

std::ostream& operator<<(std::ostream &outputStream, const Point &point);

#endif