/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:01:04 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 20:38:33 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"

DataBase::DataBase(): _first(NULL), _last(NULL) {}

DataBase::DataBase(const std::string& filename)
{
	std::ifstream infile(filename.c_str());

	if (!infile)
		throw std::runtime_error("Error: could not open file.");
	
	std::string date;
	std::string num;

	std::getline(infile, num);
	int i = 0;
	while (std::getline(infile, date, ',') && std::getline(infile, num))
	{
		if (i == 0)
		{
			_first = date;
			i ++;
		}
		_data.insert(std::make_pair(date, std::strtof(num.c_str(), NULL)));
		_last = date;
	}
}

DataBase::DataBase(const DataBase& other): _data(other._data) {}

DataBase::~DataBase() {}

float&	DataBase::operator [] (const Date& date)
{
	Date cpyDate(date);
	Date firstDate(_first);

	while (_data.find(cpyDate) == _data.end())
	{
		if (date < firstDate)
			throw std::runtime_error("Error: date too low");
		cpyDate.decDate();
	}
	return (_data[cpyDate]);
}

DataBase&	DataBase::operator = (const DataBase& other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}
