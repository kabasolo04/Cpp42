#ifndef CLASSS_HPP
#define CLASSS_HPP

#include <iostream>

class Classs
{
	private:
	
	public:
		Classs();
		Classs(const Classs& other);
		~Classs();

		Classs&	operator = (const Classs& other);
};

#endif