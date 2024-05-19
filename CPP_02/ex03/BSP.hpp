/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:27:16 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/19 17:36:44 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

#include "Fixed.hpp"
#include "Point.hpp"

Fixed crossSectionOrientation(const Point &pointA, const Point &pointB, const Point &pointToCheck);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif