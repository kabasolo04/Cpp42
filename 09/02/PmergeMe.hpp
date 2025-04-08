/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/08 13:26:28 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>

#define myList		std::list<std::list<int> >
#define myInnerList	std::list<int>
#define listSize	(long unsigned int)(1 << level)
#define befListSize	(long unsigned int)(1 << (level - (level > 0)))
class PmergeMe
{
	private:
		myList			elements;
		unsigned int	level;
		unsigned int	jacob;

		static const unsigned int	jacobsthal[];

		PmergeMe(int newLevel);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		
		void	addNums(int newNum);
		void	cpyNums();
		void	addElem(myInnerList newElem);
	
		void	getChanges(myList& elem);
		void	printElements();
	
		void	merge();
		void	insert();
	
		PmergeMe&	operator = (const PmergeMe& other);
};

#endif