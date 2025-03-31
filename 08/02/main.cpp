/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:21:32 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/26 17:36:19 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	--it;
	std::cout << "----------------------------------------------" << std::endl;
	while (++it != ite)
		std::cout << *it << std::endl;

	std::stack<int> s(mstack);
	
	return 0;
}

/*
#include <list>

int main(void)
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.back() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	--it;
	std::cout << "----------------------------------------------" << std::endl;
	while (++it != ite)
		std::cout << *it << std::endl;

	std::list<int> s(mstack);
	
	return 0;
}
*/
