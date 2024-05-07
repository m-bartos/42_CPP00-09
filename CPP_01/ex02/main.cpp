/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:49:01 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 11:42:10 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

/*
POINTERS:
Basically, pointers are “true” value types in an of themselves and can exist independently of having an object to point to. 
This is why you can have a null pointer. And since they are true value types, 
they have their own definition of the following operations, independent of the type they point to:
* To compare a pointer means to compare the memory address, not the content at that memory address.
* To copy/assign a pointer means to copy/assign the memory address, not the content at that memory address.
* Taking the address of a pointer will produce the address of the pointer object itself, not the pointed to content.
* “Dereferencing” a pointer produces a reference to the pointed to content. I know, it’s confusing. 
It made more sense in C when there wasn’t a distinct thing called a reference, so pointers were said to have “reference semantics” and
thus “dereferencing” them produced the actual content.

REFERENCES:
Because references are not true value types in and of themselves, but instead are aliases for the instance, they have the following semantics:
* They must be “bound” to an instance at initialization. A reference can never be “null.”
* They cannot be re-assigned. Assigning to a reference after it has been “bound” to an instance is equivalent to assigning to the bound instance, not the reference.
* Comparing references is equivalent to comparing the referenced instances.
* Taking the address of a reference gives the address of the bound instance.

IMPLEMENTATIONS:
* A pointer is an explicitly defined value type. They take up memory on the stack/heap.

* A reference, on the other hand, is not an explicitly defined value type. 
Because a reference isn’t a “real” value type, but instead defined as an alias to the bound instance,
the compiler is free to implement references however it wants, as long as it maintains the semantics.
*/

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "ADRESSES:" << std::endl;
	std::cout << std::setw(45) << "The memory address of the string variable:   " << &str << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringPTR:   " << stringPTR << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringREF:   " << &stringREF << std::endl; 

	std::cout << std::endl;

	std::cout << "VALUES:" << std::endl;
	std::cout << std::setw(40) << "The value of the string variable:   " << str << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringPTR:   " << *stringPTR << std::endl;
	std::cout << std::setw(40) << "The value pointed to by stringREF:   " << stringREF << std::endl;

	return (0);
}