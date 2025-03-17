/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:27:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/11 12:19:29 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define HRED	"\033[91m"
#define HBLU	"\033[94m"
#define HGRE	"\033[92m"
#define HMAG	"\033[95m"
#define RST		"\033[0m"

int main()
{
	Bureaucrat		paco("sebas", 67);
	Form			a32("a32", 60, 15);

	std::cout << HBLU << paco << RST << std::endl;
	std::cout << HMAG << a32 << RST << std::endl;

	try
	{
		Form	a34("a34", -3, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << HRED << e.what() << RST << std::endl;
	}

	paco.signForm(a32);

	return (0);
};