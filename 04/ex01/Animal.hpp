/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:45:47 by kabasolo          #+#    #+#             */
/*   Updated: 2025/01/22 12:20:11 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string newName);
		Animal(const Animal& other);
		virtual ~Animal();
		
		Animal&	operator = (const Animal& other);

		virtual void			makeSound() const;
		const std::string&		getType() const;
};

#endif