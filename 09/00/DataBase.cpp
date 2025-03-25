/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:01:04 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 12:17:59 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

DataBase::DataBase() {}

DataBase::DataBase(const std::string& filename)
{
	std::ifstream infile(filename.c_str());

	if (!infile)
		throw std::runtime_error("Error: could not open file.");
	
	std::string date;
	std::string num;

	int i = 0;
	while (std::getline(infile, date, ',') && std::getline(infile, num))
	{
		if (i == 0)
		{
			_first = date;
			i ++;
		}
		_data.insert(std::make_pair(date, std::strtof(num.c_str(), NULL)));
	}
	_last = date;
}

DataBase::DataBase(const DataBase& other): _data(other._data) {}

DataBase::~DataBase() {}

const float&	DataBase::operator [] (const std::string& date)
{
	Date tempDate(date);

	while (_data.find(tempDate.getDate()) == _data.end() || date == tempDate.)
		tempDate.decDate();
	return (_data[tempDate.getDate()]);
}

DataBase&	DataBase::operator = (const DataBase& other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}
