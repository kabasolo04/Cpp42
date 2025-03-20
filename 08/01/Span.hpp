/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 16:40:17 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	private:
		int* _nums;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		void addNumber(int n);

		Span&	operator = (const Span& other);
};

#endif