#include "Pmerge.hpp"
#include <climits>
#include <cerrno>
#include <cstdlib>

static std::vector<std::string> split_numbers(const std::string &input)
{
	std::vector<std::string> result;
	std::size_t i = 0;

	while (i < input.length())
	{
		while (i < input.length() && input[i] == ' ')
			++i;

		if (i >= input.length())
			break;

		std::size_t start = i;

		while (i < input.length() && input[i] != ' ')
			++i;

		result.push_back(input.substr(start, i - start));
	}
	return result;
}

int	main(int argc, char** argv)
{
	PmergeVector	_vector;
//	PmergeList		_list;

	if (argc != 2)
		return std::cerr << "Error\n", 1;

	std::vector<std::string> tokens = split_numbers(argv[1]);

	if (tokens.empty())
		return std::cerr << "Error\n", 1;

	for (std::size_t i = 0; i < tokens.size(); ++i)
	{
		char *end;
		errno = 0;
		long value = std::strtol(tokens[i].c_str(), &end, 10);

		if (*end != '\0' || errno == ERANGE || value < 0 || value > INT_MAX)
			return std::cerr << "Error\n", 1;

		_vector.add(static_cast<int>(value));
//		_list.add(static_cast<int>(value));
	}
	_vector.sort();
//	_list.sort();
	return 0;
}
