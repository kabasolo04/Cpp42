/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:24:11 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/10 16:57:42 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl Karen;

	Karen.complain("DEBUG");	
	Karen.complain("INFO");
	Karen.complain("WARNING");
	Karen.complain("ERROR");

	return (0);
}