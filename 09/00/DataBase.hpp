/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 12:15:47 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSS_HPP
#define CLASSS_HPP

#include "Date.hpp"

#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

class DataBase
{
	private:
		std::map<std::string, float> _data;
		std::string	_first;
		std::string	_last;

	public:
		DataBase();
		DataBase(const std::string& filename);
		DataBase(const DataBase& other);
		~DataBase();

		const std::string& first();
		const std::string& last();

		const float&	operator [] (const std::string& date);
		DataBase&		operator = (const DataBase& other);
};

#endif