# 42_CPP00-09
Basics of C++ at 42 Prague.

## Sources, literature
* CPP_00 - CPP_07 -> C++ Primer (5th edition 2013) by Stanley B. Lippman, Barbara E. Moo, Josée Lajoie
* Containers (CPP_08, CPP_09) -> The C++ Standard Library - A Tutorial and Reference by Nicolai M. Josuttis

## CPP_00
Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.

* ex00 - Megaphone
  - The goal is to output the second and other arguments of the program. If no argument is present, print the default message.
  - argc, argv, std::cout, std::endl

* ex01 - My awesome phonebook
  - The goal is to implement a Phonebook program with adding and searching functionalities.
  - *.hpp, classes, methods, public/private variables and methods, std::cin handling, getline()

* ex02 - The Job Of Your Dreams
  - The goal is to rewrite the .cpp file (make class, variables, methods etc.) from the .hpp file, main.cpp and output log of the main function.
  - *.hpp, classes, methods, public/private variables and methods
 
## CPP_01
Memory allocation, pointers to members, references, switch statement.

* ex00 - BraiiiiiiinnnzzzZ
  - The goal is to determine in what case it’s better to allocate the zombies on the stack or heap and how to destroy them correctly.
  - stack/heap object allocation (new, delete), *.hpp, classes, methods, public/private variables and methods
  
* ex01 - Moar brainz!
  - The goal is to allocate N Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as a parameter. The function returns a pointer to the first zombie.
  - stack/heap object allocation (new, delete), array of objects, *.hpp, classes, methods, public/private variables and methods
 
* ex02 - HI THIS IS BRAIN
  -  The goal of this exercise is to demystify references which can seem completely new. Although there are some little differences, this is another syntax for something you already do: address manipulation.
  - pointers, references in C++
 
* ex03 - Unnecessary violence
  - The goal of this exercise is to be able to assign the object of one class to the object of another class.
  - pointers, references in C++

* ex04 - Sed is for losers
  - Create a program that takes three parameters in the following order: a filename and two strings, s1 and s2. It will open the file <filename> and copy its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.
  - file and string manipulation (open, is_open, close, insert, erase, etc.), getline(), argc, argv, std::err

* ex05 - Harl 2.0
  - The goal of this exercise is to use pointers to member functions.
  - [pointers to member function](https://public.websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf)
 
* ex06 - Harl filter
  - The goal of this exercise is to use pointers to member functions and switch statement.
  - pointer to member function, switch

## CPP_02
Fixed point numbers

## CPP_03
Inheritance, multiple inheritance, diamond inheritance

## CPP_04
Inheritance, polymorphysm, "Interfaces", virtual and pure virtual functions

## CPP_05
Exceptions - throw, try-catch.

## CPP_06
Casting - static_cast, reinterpret_cast, dynamic_cast

* ex00 - Conversion of scalar types
  - The program takes a string as input (of char, int, float or double), detects the given type, parses it and outputs the value in the range of scalar types (char, int, float, double).
  - It has to handle edge cases (invalid input, min/max int etc.).
  - static_cast

* ex01 - Serialization
  - serialize function - converts given pointer to Data structure to uintptr_t 
  - deserialize function - converts given uintptr_t to Data pointer 
  - reinterpret_cast
  - More info about reinterpret_cast - [StackOverFLow - Is `reinterpret_cast` actually good for anything?](https://stackoverflow.com/questions/68576099/is-reinterpret-cast-actually-good-for-anything), [CPPreference - reinterpret_cast conversion](https://en.cppreference.com/w/cpp/language/reinterpret_cast)

* ex02 - Identify real type
  - dynamic_cast

## CPP_07
Templates - function templates, class templates.

## CPP_08
Containers!
* Hash tables - basic functionality [coded from scratch in C](https://www.youtube.com/watch?v=2Ti5yvumFTU&ab_channel=JacobSorber)
* STL library + containters - The C++ Standard Library - A Tutorial and Reference by Nicolai M. Josuttis

* ex00 - Easy find
  - containers

* ex01 - Span
  - containers

* ex02 - Mutated abomination
  - extending stack containter with iterator
  - class templates, inheritance
