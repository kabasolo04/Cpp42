/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:03:08 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/19 12:37:55 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *arr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i ++)
		f(arr[i]);
}

//---------------------------------------------------------------------------//

template <typename T>
void print(T &a) { std::cout << a << std::endl; }

template <typename T>
void cat(T &a) { a += "Looser "; }

template <typename T>
void plusItself(T &a) { a += a; }

#endif