#ifndef TEMPLAATE_HPP
#define TEMPLAATE_HPP

#include <iostream>

template <typename T>
class Templaate
{
	private:

	public:
		Templaate();
		Templaate(const Templaate& other);
		~Templaate();

		Templaate&		operator = (const Templaate& other);
};

#include "Templaate.tpp"

#endif