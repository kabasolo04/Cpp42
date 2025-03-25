/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:45:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 20:42:01 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSS_HPP
#define CLASSS_HPP

#include "Date.hpp"
#include <cstdlib>		//std::strtof()
#include <map>			//std::map
#include <fstream>		//std::ifstream

class DataBase
{
	private:
		std::map<Date, float> _data; // [YYYY-MM-DD]->(float bitCoin value) :D

		std::string	_first;	//turn into iterators >:(
		std::string	_last;	//turn into iterators >:(

	public:
		DataBase();
		DataBase(const std::string& filename);
		DataBase(const DataBase& other);
		~DataBase();

		float&	operator [] (const Date& date);
		DataBase&		operator = (const DataBase& other);
};

#endif