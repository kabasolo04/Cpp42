/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:42:12 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/24 20:39:56 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

const int Date::daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(): _year(0), _month(0), _day(0) {}

static bool leapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::valiDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (0);
	
	std::istringstream ss(date);
	
	int     year, month, day;
	char    sign1, sign2;

	ss >> year >> sign1 >> month >> sign2 >> day;

	if (ss.fail() || sign1 != '-' || sign2 != '-')
		return (0);
	if (month < 1 || month > 12 || day < 1)
		return (0);

	return day <= daysInMonth[month] + leapYear(_year) * (_month == 2);
}

Date::Date(const std::string& date)
{
	if (!valiDate(date))
		throw std::runtime_error("Error: bad input => " + date);

	std::istringstream ss(date);

	char    sign1, sign2;

	ss >> _year >> sign1 >> _month >> sign2 >> _day;
}

Date::Date(const Date& other): _year(other._year), _month(other._month), _day(other._day) {}

Date::~Date() {}

void Date::decDate()
{
	if (--_day < 1)
	{
		if (--_month < 1)
		{
			_month = 12;
			--_year;
		}
		_day = daysInMonth[_month] + leapYear(_year) * (_month == 2);
	}
}

void Date::incDate()
{
	if (++_day > daysInMonth[_month] + leapYear(_year) * (_month == 2))
	{
		_day = 1;
		if (++_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
}

std::string Date::getDate()
{
	std::ostringstream oss;

	oss << _year << "-";
	if (_month < 10)
		oss << "0";
	oss << _month << "-";
	if (_day < 10)
		oss << "0";
	oss << _day;

	return oss.str();
}

Date&	Date::operator = (const Date& other) 
{
	if (this != &other)
	{
		_year = other._year;
		_month = other._month;
		_day = other._day;

	}
	return (*this);
}
