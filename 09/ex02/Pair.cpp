#include "Pair.hpp"

Pair::Pair():
	num(0),
	winner(NULL),
	looser(NULL) {}

Pair::Pair(int single):
	num(single),
	winner(NULL),
	looser(NULL) {}

Pair::Pair(const Pair& single):
	num(single.num),
	winner(single.winner),
	looser(single.looser) {}

Pair::Pair(const Pair& single, int StranglerFlag):	// Strangler Constructor
	num(single.num),
	winner(NULL),
	looser(&single) { (void)StranglerFlag; }

Pair::Pair(const Pair& a, const Pair& b)
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

Pair::~Pair() {}

bool	Pair::isStrangler() { return (winner == NULL && looser != NULL); }