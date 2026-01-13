#include "Pmerge.hpp"

Pmerge::Pmerge() {}
Pmerge::Pmerge(const Pmerge& other) { *this = other; }
Pmerge::~Pmerge() {}

Pmerge&	Pmerge::operator = (const Pmerge& other)
{
	if (this != &other)
		_vector = other._vector;
	return (*this);
}

//static long getElapsedTimeUs(const struct timeval& start, const struct timeval& end)
//{
//	return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
//}

void	printPairs(std::vector<Pair>& pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << pairs[i].num << " ";
	}
	std::cout << std::endl;
}

//static void	printPairs(std::list<Pair>& pairs)
//{
//	for (std::list<Pair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
//	{
//		std::cout << it->num << " ";
//	}
//	std::cout << std::endl;
//}

void	Pmerge::add(int num)
{
	Pair	temp(num);

	_vector.push_back(temp);
	_list.push_back(temp);
}

static const char*	isOrdered(const std::vector<Pair>& pairs)
{
	if (pairs.size() < 2)
		return "yes";

	for (size_t i = 1; i < pairs.size(); ++i)
	{
		if (pairs[i - 1].num > pairs[i].num)
		{
			return "no";
		}
	}
	return "yes";
}

void	Pmerge::sort()
{
//	std::cout << "Time to process a range of " << _vector.size() << std::endl;
//	std::cout << "Before: ";
//	printPairs(_vector);

	gettimeofday(&_start, NULL);

	fordJonhson(_vector);

	gettimeofday(&_end, NULL);
	
//	std::cout << "After: ";
//	printPairs(_vector);

	std::cout << isOrdered(_vector) << std::endl;
//	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << getElapsedTimeUs(_start, _end) << " us" << std::endl;
	
//	std::cout << "Before: ";
//	printPairs(_list);
//
//	gettimeofday(&_start, NULL);
//
//	fordJonhson(_list);
//
//	gettimeofday(&_end, NULL);
//	
//	std::cout << "After: ";
//	printPairs(_list);
//
//	std::cout << "Time to process a range of " << _list.size() << " elements with std::vector : " << getElapsedTimeUs(_start, _end) << " us" << std::endl;
}
