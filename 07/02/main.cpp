/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:02:26 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/20 13:30:34 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
	Array<std::string> temp(5);
	for (unsigned int i = 0; i < temp.size(); i ++)
		temp[i] = "heloo";
	const Array<std::string> arr(temp);

	try
	{
		for (unsigned int i = 0; i < arr.size(); i ++)
			std::cout << arr[i] << std::endl;

		Array<std::string> cpy;
		cpy = arr;
		
		for (unsigned int i = 0; i < cpy.size(); i ++)
			std::cout << cpy[i] << std::endl;
		//std::string& temp1 = arr[0];
		std::string& temp2 = cpy[0];
		temp2 = "byeeeee";
		std::cout << arr[0] << std::endl;
		std::cout << cpy[0] << std::endl;
		std::cout << temp[0] << std::endl;
		//arr[0] = cpy[0];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}