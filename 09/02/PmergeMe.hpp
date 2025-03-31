/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/31 13:37:03 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>

class PmergeMe
{
	private:
		std::list<std::list<int>>	elements;
		static int					level;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		void	addNums(int newNum);
		void	addElem(const std::list<int>& newElem);
		void	sortIt();
		std::list<std::list<int>>&	PmergeMe::getElements();

		PmergeMe&	operator = (const PmergeMe& other);
};

#endif