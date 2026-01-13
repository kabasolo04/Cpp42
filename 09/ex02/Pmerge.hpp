/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:02:39 by kabasolo          #+#    #+#             */
/*   Updated: 2026/01/02 12:50:24 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>
#include "Pair.hpp"

class Pmerge
{
	private:
		std::vector<Pair>	_vector;
		std::list<Pair>		_list;

		struct timeval		_start;
		struct timeval		_end;
		
	public:
		Pmerge();
		Pmerge(const Pmerge& other);
		~Pmerge();

		Pmerge&	operator = (const Pmerge& other);

		void	add(int num);
		void	sort();
};

#endif

void	fordJonhson(std::vector<Pair>& incoming);
void	printPairs(std::vector<Pair>& pairs);
