/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:46 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/11 20:20:23 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const unsigned int PmergeMe::jacobsthal[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203 };

PmergeMe::PmergeMe():level(0) {}

PmergeMe::PmergeMe(int newLevel):level(newLevel) {}

PmergeMe::PmergeMe(const PmergeMe& other): listElements(other.listElements){}

PmergeMe::~PmergeMe() {}

void	PmergeMe::addNums(int newNum)
{
	std::list<int> temp;
	temp.push_front(newNum);
	listElements.push_back(temp);
}

void	PmergeMe::addElem(std::list<int> newElem)
{
	if (newElem.size() < befListSize)
		return ;

	else if (listElements.size() == 0) //First element of the list
		listElements.push_back(newElem);

	else if (listElements.back().size() == listSize) //Last element FULL
		listElements.push_back(newElem);

	else if (listElements.back().size() < listSize) //Last element NOT FULL
	{
		if (listElements.back().back() < newElem.back()) //Gotta merge after
			listElements.back().splice(listElements.back().end(), newElem);
		else
		{
			newElem.splice(newElem.end(), listElements.back()); //Gotta merge bef.
			listElements.back().swap(newElem);
		}
	}
}

void	PmergeMe::merge()
{
	if (listElements.size() < 2)
		return ;
	if (listElements.size() == 2 && listElements.front().size() != listElements.back().size())
		return ;
	
	PmergeMe temp(level + 1);

	std::cout << level << ": ";
	printElements();

	myList::iterator	it;
	for (it = listElements.begin(); it != listElements.end(); ++it)
		temp.addElem(*it);

	temp.merge();
	temp.getChanges(listElements);

	insert();

	std::cout << level << ": ";
	printElements();
}

/*
	myList::iterator	it = ++listElements.begin();
	unsigned int		itJacob = 0;
	unsigned int		jacob = 0;

	while (it != listElements.end() && ++it != listElements.end())
	{
		myList::iterator	ite = listElements.begin();
		myList::iterator	current = it++;
		unsigned int		i = 0;

		if ((*current).size() != listSize)
			return ;
	
		std::cout << (*current).back() << ": " << jacobsthal[jacob] + itJacob << std::endl;
		
		while (ite != listElements.end() && (*ite).size() == listSize && i < jacobsthal[jacob] + itJacob && !((*current).back() < (*ite).back()))
			i += (current != ite++);

		listElements.splice(ite, listElements, current);

		jacob += (++itJacob == jacobsthal[jacob] - 1);
	}
*/

/*
		i = jacobsthal[jacob - 1];
		while (i < jacobsthal[jacob])
		{
			if (++it == listElements.end() || (*it).size() != listSize)
			{
				it --;
				flag = 0;
				break ;
			}
			if (++it == listElements.end() || (*it).size() != listSize)
			{
				it --;
				it --;
				flag = 0;
				break ;
			}
			i ++;
		}
*/

void	PmergeMe::insert()
{
	myList::iterator	it = ++listElements.begin();
	//unsigned int		jacob = 1;
	//unsigned int		i = 0;
	//char				flag = 1;
	myList				pend;
	
	while (++it != listElements.end() || (*it).size() == listSize)
	{
		pend.push_front(*it);
		it = listElements.erase(it);
		if (it == listElements.end() || (*it).size() != listSize)
			break ;
	}
	
	it = ++listElements.begin();

	while (pend.size())
	{
		
	}
	
	/*
	while (flag)
	{
		myList	pend;
		i = jacobsthal[jacob - 1];
		
		myList::iterator	temp = it;
		myList::iterator	bef = --temp;

		while (listElements.begin() != temp && (*bef).back() > (*temp).back())
			temp --;

		listElements.splice(temp, listElements, it++);
		
		std::cout << "i: " << i << " jakovo: " << jacobsthal[jacob] - jacobsthal[jacob - 1];
		
		std::cout << " ola " << (*it).back() << std::endl;

		i = jacobsthal[jacob] - jacobsthal[jacob - 1];
		jacob ++;
	}
		*/
}

/*
		while (it != listElements.end() && ++it != listElements.end())
			if (++i >= jacobsthal[jacob])
				break ;

		std::cout << (*it).back() << std::endl;
	
		myList::iterator	temp = it;
		myList::iterator	bef = --temp;

		while (listElements.begin() != temp && (*bef).back() > (*temp).back())
			temp --;

		listElements.splice(temp, listElements, it++);

*/

void	PmergeMe::printElements()
{
	myList::iterator it;
	for (it = listElements.begin(); it != listElements.end(); it++)
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
	myList&	A(listElements);
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
