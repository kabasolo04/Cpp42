/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:46 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/31 13:49:18 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::level = 0;

PmergeMe::PmergeMe() {level ++;}

PmergeMe::PmergeMe(const PmergeMe& other) {}

PmergeMe::~PmergeMe() {level --;}

void	PmergeMe::addNums(int newNum)
{
	elements.push_front(std::list<int>(newNum));
}

void	PmergeMe::addElem(const std::list<int>& newElem)
{
	std::list<int> temp(newElem);

	if (elements.size() == 0 || elements.front().size() == level)
	{
		elements.push_front(temp);
		return ;
	}

	if (elements.front().front() < newElem.front())
	{
		elements.front().splice(elements.front().end(), temp);
		return ;
	}

	elements.front().swap(temp);
}

void	PmergeMe::sortIt()
{

}

std::list<std::list<int>>&	PmergeMe::getElements()
{
	return (elements);
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return (*this);
}