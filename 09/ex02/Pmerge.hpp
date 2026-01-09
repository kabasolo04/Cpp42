/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeVector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:02:39 by kabasolo          #+#    #+#             */
/*   Updated: 2026/01/02 12:50:24 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sys/time.h>

struct Pair;

class PmergeVector
{
	private:
		std::vector<Pair>	_vector;
		struct timeval		_start;
		struct timeval		_end;
		
	public:
		PmergeVector();
		PmergeVector(const PmergeVector& other);
		~PmergeVector();

		PmergeVector&	operator = (const PmergeVector& other);

		void	add(int num);
		void	sort();
};

#endif

struct Pair
{
	const Pair*	winner;
	const Pair*	looser;

	int			num;
	bool		strangler;

	Pair(int single): winner(NULL), looser(NULL), num(single), strangler(0) {}

	Pair(const Pair& single): winner(single.winner), looser(single.looser), num(single.num), strangler(single.strangler) {}

	Pair(const Pair& single, int flag): winner(NULL), looser(&single), num(single.num), strangler(1) { (void)flag; }

	Pair(const Pair& a, const Pair& b)
	{
		if (a.num > b.num)
		{
			num = a.num;
			winner = &a;
			looser = &b;
		}
		else
		{
			num = b.num;
			winner = &b;
			looser = &a;
		}
	}

	//Pair&	operator = (const Pair& other)
	//{
	//	if (this != &other)
	//	{
	//		num			= other.num;
	//		strangler	= other.strangler;
	//		winner		= &other;
	//		looser		= other.looser;
	//	}
	//	return *this;
	//}

	bool	isStrangler() { return strangler; }
};

//class PmergeList
//{
//	private:
//		std::list<int>	_list;
//		struct timeval	_start;
//		struct timeval	_end;
//		
//	public:
//		PmergeList();
//		PmergeList(const PmergeList& other);
//		~PmergeList();
//
//		void	add(int num);
//		void	sort();
//
//		PmergeVector&	operator = (const PmergeVector& other);
//};
