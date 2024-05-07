/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartos <mbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:41:18 by mbartos           #+#    #+#             */
/*   Updated: 2024/05/07 15:57:41 by mbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceWords(std::ifstream& inputFile, std::ofstream& outputFile, std::string searchWord, std::string replaceWord) {
	std::string	line; // Declare a string variable to store each line of text

	while (std::getline(inputFile, line)) { // Loop through each line in the input file
		size_t	pos = line.find(searchWord); // Find the position of the first searchWord in the line

		while (pos != std::string::npos) { // Repeat until all occurrences are replaced in the line
			line.erase(pos, searchWord.length()); // Erase searchWord
			line.insert(pos, replaceWord); // Insert replaceWord instead
			pos = line.find(searchWord, pos + replaceWord.length()); // Find the next occurrence of the searchWord in the line
		}
		outputFile << line << "\n"; // Write the modified line to the output file
	}
}

int main(int argc, char **argv) {
	if (argc == 4) {
		std::ifstream	inputFile(argv[1]); // Open the input file
		if(!inputFile.is_open()) {
			std::cout << "ERROR: Failed to open infile." << std::endl;
			return (EXIT_FAILURE);
		}

		std::string		outFileName = std::string(argv[1]) + ".replace";
		std::ofstream	outputFile(outFileName); // Create or overwrite the output file
		if(!outputFile.is_open()) {
			std::cout << "ERROR: Failed to open outfile." << std::endl;
			inputFile.close();
			return (EXIT_FAILURE);
		}

		std::string		searchWord = argv[2]; 
		// Check if searchWord is not empty (!= "")
		if (searchWord == "") {
			inputFile.close();
			outputFile.close();
			std::cout << "ERROR: Word to find cannot be empty!" << std::endl;
			return (EXIT_FAILURE);
		}

		std::string		replaceWord = argv[3]; 

		replaceWords(inputFile, outputFile, searchWord, replaceWord);

		inputFile.close();
		outputFile.close();

		std::cout << "All words \""<< argv[2] <<"\" were replaced successfully by \"" << argv[3] << "\" in file \""
				  << argv[1] << "\" to new file \"" << outFileName << "\"." << std::endl;
		return (EXIT_SUCCESS);
	}
	std::cout << "ERROR: Correct syntax is \"./sed_is_for_losers <filename> <word_to_find> <replace_with>\"" << std::endl;
	return (EXIT_FAILURE);
}
