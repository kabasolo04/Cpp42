/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:50:02 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 11:57:41 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

static void checkBitCoin(DataBase data, std::string line)
{
	try
	{
		float bitValue = data[line.substr(0, 10)];
		(void)bitValue;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main(int argc, char **argv)
{
	if (argc > 2)
		return (std::cout << "Error: to many arguments." << std::endl, 1);
	
	std::ifstream infile(argv[1]);

	if (!infile)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	
	DataBase	data("data.csv");
	std::string	line;

	if (std::getline(infile, line, '\n') && line != "date | value")
		return (std::cout << "Error: non valid format." << std::endl, 1);
	
	while (std::getline(infile, line, '\n'))
		checkBitCoin(data, line);

	return (0);
}