#include "Classs.hpp"

Classs::Classs() {}

Classs::Classs(const Classs& other) {*this = other;}

Classs::~Classs() {}

Classs&	Classs::operator = (const Classs& other)
{
	if (this != &other)
	{

	}
	return (*this);
}