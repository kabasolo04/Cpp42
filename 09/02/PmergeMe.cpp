/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:46 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/07 15:35:22 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():level(0) {}

PmergeMe::PmergeMe(int newLevel):level(newLevel) {}

PmergeMe::PmergeMe(const PmergeMe& other): elements(other.elements){}

PmergeMe::~PmergeMe() {}

void	PmergeMe::addNums(int newNum)
{
	std::list<int> temp;
	temp.push_front(newNum);
	elements.push_back(temp);
}

void	PmergeMe::addElem(std::list<int> newElem)
{
	if (newElem.size() < (long unsigned int)(1 << (level - (level > 0))))
		return ;

	else if (elements.size() == 0) //First element of the list
		elements.push_back(newElem);

	else if (elements.back().size() == (long unsigned int)(1 << level)) //Last element FULL
		elements.push_back(newElem);
	
	else if (elements.back().size() < (long unsigned int)(1 << level)) //Last element NOT FULL
	{
		if (elements.back().back() < newElem.back()) //Gotta merge after
			elements.back().splice(elements.back().end(), newElem);
		else
		{
			newElem.splice(newElem.end(), elements.back()); //Gotta merge bef.
			elements.back().swap(newElem);
		}
	}
}

void	PmergeMe::merge()
{
	PmergeMe temp(level + 1);
	
	std::list<std::list<int> >::iterator	it;
	for (it = elements.begin(); it != elements.end(); ++it)
		temp.addElem(*it);
	
	//std::cout << level << ":";
	//temp.printElements();

	if (temp.elements.size() > 2)
		temp.merge();
	else if (temp.elements.size() == 2 && temp.elements.back().size() == (long unsigned int)(1 << (level - (level > 0))))
		temp.merge();

	temp.getChanges(elements);

	insert();
}

void	PmergeMe::insert()
{
	
}

void	PmergeMe::printElements()
{
	std::list<std::list<int> >::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
	{
		std::list<int>::iterator ite;
		for (ite = it->begin(); ite != it->end(); ite++)
			std::cout << " " << *ite;
		std::cout << " |";
	}
	std::cout << std::endl;
}

void	PmergeMe::getChanges(std::list<std::list <int> >& elem)
{
	std::list<std::list<int> >& A(elements);
	std::list<std::list<int> >& B(elem);

	std::list<std::list<int> >::iterator itA;
	std::list<std::list<int> >::iterator itB = B.begin();

	std::list<int>::iterator itInnerA;
	std::list<int>::iterator itInnerB = (*itB).begin();

	for (itA = A.begin(); itA != A.end(); itA++)
	{
		for (itInnerA = (*itA).begin(); itInnerA != (*itA).end(); itInnerA++)
		{
			*itInnerB = *itInnerA;
			if (++itInnerB == (*itB).end())
				itInnerB = (*(++itB)).begin();
		}
	}
}

PmergeMe&	PmergeMe::operator = (const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return (*this);
}
