/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeName.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:15:47 by mbartos           #+#    #+#             */
/*   Updated: 2024/08/28 15:11:38 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPENAME_HPP
#define TYPENAME_HPP

#include <vector>
#include <deque>
#include <string>

template <typename T>
std::string getTypeName() {
	return "Unknown type";
}

// Specializations for known types
template <>
std::string getTypeName<std::vector<unsigned int> >() {
	return "std::vector<unsigned int>";
}

template <>
std::string getTypeName<std::deque<unsigned int> >() {
	return "std::deque<unsigned int>";
}

#endif