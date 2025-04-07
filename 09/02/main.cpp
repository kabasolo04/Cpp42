/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:19 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/07 13:57:55 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//int main(int argc, char **argv)
int main()
{
	PmergeMe a;

	std::list<int> temp;

	temp.push_front(9);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(7);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(8);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(2);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(0);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(3);
	a.addElem(temp);
	temp.pop_front();
	temp.push_front(4);
	a.addElem(temp);

	a.printElements();

	a.merge();

	a.printElements();

	return (0);
}
