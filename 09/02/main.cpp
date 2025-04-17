/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:52:19 by kabasolo          #+#    #+#             */
/*   Updated: 2025/04/15 15:47:46 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//int main(int argc, char **argv)
int main()
{
	PmergeMe a;

	a.addNums(2);
	a.addNums(8);
	a.addNums(1);
	a.addNums(9);
	a.addNums(5);
	a.addNums(3);
	a.addNums(6);
	a.addNums(7);
	a.addNums(5);

	      
	
	a.printElements();

	a.merge();

	a.printElements();

	return (0);
}
