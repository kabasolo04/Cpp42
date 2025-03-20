/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:06:25 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/19 12:38:11 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{
	int arr[] =	{1, 1, 1, 1, 1};
	char charr[] = {'!', '!', '!', '!'};
	std::string A[] = {"Hello ", "Bye "};

	iter(arr, 5, print);
	iter(arr, 5, plusItself);
	iter(arr, 5, print);
	iter(arr, 5, plusItself);
	iter(arr, 5, print);

	iter(charr, 4, print);
	iter(charr, 4, plusItself);
	iter(charr, 4, print);

	iter(A, 2, print);
	iter(A, 2, cat);
	iter(A, 2, print);

	iter(A, 2, print);
	iter(A, 2, plusItself);
	iter(A, 2, print);
}
