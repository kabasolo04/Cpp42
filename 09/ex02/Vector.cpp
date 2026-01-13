#include "Pmerge.hpp"

static void binaryInsert(std::vector<Pair>& ordered, const Pair& value)
{
	size_t left = 0;
	size_t right = ordered.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (value.num < ordered[mid].num)
			right = mid;
		else
			left = mid + 1;
	}
	ordered.insert(ordered.begin() + left, value);
}

static std::vector<Pair> insert(std::vector<Pair>& current)
{
	std::vector<Pair>	loosers;
	std::vector<Pair>	winners;

	for (size_t i = 0; i < current.size(); i ++)
	{
		if (current[i].winner != NULL)
			winners.push_back(*current[i].winner);
		if (current[i].looser != NULL)
			loosers.push_back(*current[i].looser);
		else if (current[i].winner == NULL)
			loosers.push_back(current[i]);
	}

	size_t inserted = 0;
	size_t j = 1;

	while (inserted < loosers.size())
	{
		size_t limit = std::min(j, loosers.size());

		for (size_t i = limit; i > inserted; --i)
			binaryInsert(winners, loosers[i - 1]);

		inserted = limit;
		j = j * 2 + 1; // Jacobsthal progression
	}
	return winners;
}

static std::vector<Pair> merge(std::vector<Pair>& incoming)
{
	std::vector<Pair>	out;
	size_t				i = 0;

	while (i + 1 < incoming.size())
	{
		Pair&	a = incoming[i];
		Pair&	b = incoming[i + 1];
		
		if (b.isStrangler())
			break;

		out.push_back(Pair(a, b));
		i += 2;
	}

	if (i < incoming.size() && !incoming[i].isStrangler())
		out.push_back(Pair(incoming[i], 0));

	return out;
}

void	fordJonhson(std::vector<Pair>& incoming)
{
	if (incoming.size() <= 1)
		return;

	std::vector<Pair>	pairs = merge(incoming);

	fordJonhson(pairs);

	if (incoming.back().isStrangler())
		pairs.push_back(incoming.back());

	incoming = insert(pairs);
}
