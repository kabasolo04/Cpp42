#include "Pmerge.hpp"

PmergeVector::PmergeVector() {}
PmergeVector::PmergeVector(const PmergeVector& other) { *this = other; }
PmergeVector::~PmergeVector() {}

PmergeVector&	PmergeVector::operator = (const PmergeVector& other)
{
	if (this != &other)
		_vector = other._vector;
	return (*this);
}

static long getElapsedTimeUs(const struct timeval& start, const struct timeval& end)
{
	return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

static void	printPairs(std::vector<Pair>& pairs)
{
	std::cout << "----------------------------------\n";

	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "Winner: " << pairs[i].num << " | Looser: ";

		if (pairs[i].looser == NULL)
			std::cout << "None";
		else
			std::cout << pairs[i].looser->num;
		
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void	PmergeVector::add(int num)
{
	_vector.push_back(Pair(num));
}

//static void insert(std::vector<Pair>& current)
//{
//
//}

//static std::vector<Pair> reOrder(const std::vector<Pair>& incoming, const std::vector<Pair>& current)
//{
//
//}

//static std::vector<Pair> merge(std::vector<Pair>& incoming)
//{
//	std::vector<Pair>	out;
//	size_t				i = 0;
//
//	while (i + 1 < incoming.size())
//	{
//		Pair&	a = incoming[i++];
//		Pair&	b = incoming[i++];
//
//		if (b.looser == NULL)
//			out.push_back(Pair(a));
//
//		out.push_back(Pair(a, b));
//	}
//
//	if (i < incoming.size())
//		out.push_back(Pair(incoming[i])); // Strangler
//
//	return out;
//}

//static void	fordJonhson(std::vector<Pair>& incoming)
//{
//	if (incoming.size() <= 1)
//		return;
//
//	std::vector<Pair>	pairs = merge(incoming);
//
//	LeaderBoard	leaderBoard(pairs);
//
//	fordJonhson(leaderBoard.winners);
//
//	incoming = insert(pairs, leaderBoard);
//}

static std::vector<Pair> merge(std::vector<Pair>& incoming)
{
	std::vector<Pair>	out;
	size_t				i = 0;

	while (i + 1 < incoming.size())
	{
		out.push_back(Pair(incoming[i], incoming[i + 1])); 
		i += 2;
	}
	if (i < incoming.size() && incoming[i].isStrangler() == false)
		out.push_back(Pair(incoming[i], 0));

	return out;
}

static void	fordJonhson(std::vector<Pair>& incoming)
{
	printPairs(incoming);

	if (incoming.size() <= 1)
		return;

	std::vector<Pair>	pairs = merge(incoming);

	fordJonhson(pairs);
//
//	incoming = insert(pairs);
}

void	PmergeVector::sort()
{
	gettimeofday(&_start, NULL);

	fordJonhson(_vector);

	gettimeofday(&_end, NULL);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << getElapsedTimeUs(_start, _end) << " us" << std::endl;

}
