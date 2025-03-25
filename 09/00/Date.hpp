/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:40:04 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/25 12:09:04 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Date_HPP
#define Date_HPP

#include <iostream>
#include <sstream>

class Date
{
	private:
		int	_year;
		int	_month;
		int	_day;

		static const int daysInMonth[13];

	public:
		Date();
		Date(const std::string& date);
		Date(const Date& other);
		~Date();

		void decDate();
		void incDate();
		std::string getDate();
		bool valiDate(const std::string& date);

		Date&				operator = (const Date& other);
};


#endif