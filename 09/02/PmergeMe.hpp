/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/16 17:57:50 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define myList		std::list<std::list<int> >
#define myInnerList	std::list<int>
#define myVector	std::vector<int>
#define listSize	(long unsigned int)(1 << level)
#define befListSize	(long unsigned int)(1 << (level - (level > 0)))

class PmergeMe
{
	private:
		myList			listElements;
		myVector		vecElements;
		unsigned int	level;

		static const unsigned int	jacobsthal[];

		PmergeMe(int newLevel);
		void	insert();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		
		void	addNums(int newNum);
		void	addElem(myInnerList newElem);
	
		void	getChanges(myList& elem);
		void	printElements();

		void	merge();
		void	startList();
		void	startVec();
	
		PmergeMe&	operator = (const PmergeMe& other);
};

#endif