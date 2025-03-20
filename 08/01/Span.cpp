/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:36 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 16:42:29 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n): _nums(new int[n]) {}

Span::Span(const Span& other) {*this = other;}

Span::~Span() { delete[] _nums;}

Span&	Span::operator = (const Span& other)
{
	if (this != &other)
	{

	}
	return (*this);
}