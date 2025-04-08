/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:46 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/08 13:25:33 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const unsigned int PmergeMe::jacobsthal[] = { 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203 };

PmergeMe::PmergeMe():level(0), jacob(0) {}

PmergeMe::PmergeMe(int newLevel):level(newLevel), jacob(0) {}

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
	if (newElem.size() < befListSize)
		return ;

	else if (elements.size() == 0) //First element of the list
		elements.push_back(newElem);

	else if (elements.back().size() == listSize) //Last element FULL
		elements.push_back(newElem);

	else if (elements.back().size() < listSize) //Last element NOT FULL
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
	if (elements.size() < 2)
		return ;
	if (elements.size() == 2 && elements.front().size() != elements.back().size())
		return ;
	
	PmergeMe temp(level + 1);

	std::cout << level << ": ";
	printElements();

	myList::iterator	it;
	for (it = elements.begin(); it != elements.end(); ++it)
		temp.addElem(*it);

	temp.merge();

	temp.getChanges(elements);
	std::cout << level << ": ";
	printElements();
	insert();
	std::cout << level << ": ";
	printElements();
}

/*
	myList::iterator	it = ++elements.begin();
	unsigned int		itJacob = 1;
	unsigned int		jacob = 0;

	while (it != elements.end() && ++it != elements.end())
	{
		myList::iterator	ite = elements.begin();
		myList::iterator	current = it++;
		unsigned int		i = 0;
	
		if ((*current).size() != befListSize)
			return ;
		
		while (ite != elements.end() && i < jacobsthal[jacob] && !( (*current).back() < (*ite).back() ))
			i += (current != ite++);

		elements.splice(ite, elements, current);

		jacob += (++itJacob == jacobsthal[jacob]);
	}
*/

void	PmergeMe::insert()
{

}

void	PmergeMe::printElements()
{
	myList::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
	{
		myInnerList::iterator ite;
		for (ite = it->begin(); ite != it->end(); ite++)
			std::cout << " " << *ite;
		std::cout << " |";
	}
	std::cout << std::endl;
}

void	PmergeMe::getChanges(std::list<std::list <int> >& elem)
{
	myList&	A(elements);
	myList&	B(elem);

	myList::iterator	itA;
	myList::iterator	itB = B.begin();

	myInnerList::iterator itInnerA;
	myInnerList::iterator itInnerB = (*itB).begin();

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
