/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:57:58 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/17 18:15:01 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cerrno>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		
	public:
		static void convert(std::string input);
};

#endif