#include <iostream>

class Pair
{
	public:
		int			num;
		const Pair*	winner;
		const Pair*	looser;

		Pair();
		Pair(int single);
		Pair(const Pair& single);
		Pair(const Pair& single, int StranglerFlag);
		Pair(const Pair& a, const Pair& b);
		~Pair();

		bool	isStrangler();
};