/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:22 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/07 15:27:22 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>

class PmergeMe
{
	private:
		std::list<std::list <int> >	elements;
		unsigned int				level;

		PmergeMe(int newLevel);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		
		void	addNums(int newNum);
		void	cpyNums();
		void	addElem(std::list<int> newElem);
	
		void	getChanges(std::list<std::list <int> >& elem);
		void	printElements();
	
		void	merge();
		void	insert();
	
		PmergeMe&	operator = (const PmergeMe& other);
};

#endif