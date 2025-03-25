/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:50:02 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 20:37:25 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"
#include <cmath>

static void checkBitCoin(DataBase& data, std::string line)
{
	try
	{
		Date date(line.substr(0, 10));
		float bitValue = data[date];
		if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
			throw std::runtime_error("Error: syntax error");
	
        std::string valueStr = line.substr(13);

        char* endptr;
        float f = std::strtof(valueStr.c_str(), &endptr);
	
		if (endptr[0] != '\0' && endptr[0] != '\n')
			throw std::runtime_error("Error: syntax error");
		if (std::isnan(f))
			throw std::runtime_error("Error: nanf");
		if (f < 0)
			throw std::runtime_error("Error: not a possitive number");
		if (f >= 2147483648)
			throw std::runtime_error("Error: to large a number");
	
		std::cout << date.getDate() << " => " << f << " = " << f * bitValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int argc, char **argv)
{
	std::ifstream	infile(argv[1]);
	std::string		line;

	if (argc > 2)
		return (std::cout << "Error: to many arguments." << std::endl, 1);
	
	if (!infile)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	
	if (std::getline(infile, line, '\n') && line != "date | value")
		return (std::cout << "Error: non valid format." << std::endl, 1);
	
	DataBase	data("data.csv");

	while (std::getline(infile, line, '\n'))
		checkBitCoin(data, line);

	return (0);
}
