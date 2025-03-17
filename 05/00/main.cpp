/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 12:08:35 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	//Bureaucrat pepe("pepe", 0);
	try
	{
		Bureaucrat pepe("pepe", 1);
		//pepe.incGrade();
		//pepe.decGrade();
		std::cout << pepe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
