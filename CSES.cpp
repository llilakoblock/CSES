// CSES.cpp : Defines the entry point for the application.
//
#include "CSES.h"

#include <algorithm>
#include <cassert>
#include <cmath>

std::vector<int64_t> CSES::weird_algorithm(int64_t n)
{
	assert(1 <= n);
	assert(n <= static_cast<int64_t>(pow(10, 6)));

	std::vector<int64_t> res{ n };

	do
	{
		if (n % 2 == 0) //even
			n /= 2;
		else //odd
			n = n * 3 + 1;

		res.push_back(n);

	} while (n != 1);

	return res;
}

std::vector<int64_t> CSES::missing_number(int64_t n, std::vector<int64_t> numbers)
{
	assert(2 <= n);
	assert(n <= 2 * static_cast<int64_t>(pow(10, 5)));
	std::sort(numbers.begin(), numbers.end());

	int64_t i = 1;
	std::vector<int64_t> res;

	for (long long& number : numbers)
	{
		if (number != i)
			res.push_back(i);
		i++;
	}
	return res;
}

int64_t CSES::repetition(const std::string& input)
{
	if (input.empty())
		return 0;
	if (input.size() < 2)
		return 1;

	int64_t count = 1, max = 0;
	char prev_ch = input.at(0);
	for (auto itr = input.begin() + 1; itr != input.end(); ++itr)
	{
		if (*itr == prev_ch)
		{
			++count;
			max = std::max(count, max);
		}
		else
		{
			prev_ch = *itr;
			count = 1;
		}
	}

	return max;
}

int64_t CSES::increasing_array(std::vector<int64_t>& array)
{
	if (array.empty())
		return 0;
	if (array.size() < 2)
		return -1;

	int64_t move_count = 0;
	auto prev_elem = array.begin();
	for (auto itr = array.begin() + 1; itr != array.end(); ++itr)
	{
		if (*itr < *prev_elem)
		{
			move_count += *prev_elem - *itr;
			*itr = *prev_elem;
		}

		prev_elem = itr;
	}

	return move_count;
}

std::vector<int64_t> CSES::permutation_integers(int64_t n)
{
	if (n <= 3)
		return {};

	std::vector<int64_t> ret;

	if (n % 2 == 0)
	{
		for (int i = 2; i <= n; i += 2)
		{
			ret.push_back(i);
		}

		for (int j = 1; j < n; j += 2)
		{
			ret.push_back(j);
		}
	}
	else
	{
		for (int i = 2; i <= n - 1; i += 2)
		{
			ret.push_back(i);
		}

		for (int j = 1; j <= n; j += 2)
		{
			ret.push_back(j);
		}
	}

	return ret;

}

void CSES::two_knights(int64_t n)
{
	std::cout << 0 << std::endl;
	for (long long i = 2; i <= n; i++) {
		int64_t res = (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1));
		std::cout << res << std::endl;
	}
}

void CSES::two_sets(int64_t n)
{
	std::vector<int64_t> first_set;
	std::vector<int64_t> second_set;

	if (n % 2 == 0)
	{
		for (auto i = 0; i < n / 2; ++i)
		{
			if (i % 2 == 0)
			{
				first_set.push_back(i + 1);
				first_set.push_back(n - i);
			}
			else
			{
				second_set.push_back(i + 1);
				second_set.push_back(n - i);
			}
		}
	}
	else
	{
		for (auto i = 0; i < (n - 1) / 2 ; ++i)
		{
			if (i % 2 == 0)
			{
				first_set.push_back(i + 1);
				first_set.push_back(n - i - 1);
			}
			else
			{
				second_set.push_back(i + 1);
				second_set.push_back(n - i - 1);
			}
		}
	}

	if (first_set.size() > second_set.size())
		second_set.push_back(n);
	else
		first_set.push_back(n);

	std::cout << std::endl << first_set.size() << std::endl;
	for (auto i : first_set)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl << second_set.size() << std::endl;
	for (auto i : second_set)
	{
		std::cout << i << " ";
	}

}

void CSES::two_piles(int64_t p1, int64_t p2)
{
	if (p1 == p2)
	{
		std::cout << std::endl << "NO";
		return;
	}

	if(std::max(p1,p2) > std::min(p1, p2) * 2)
	{
		std::cout << std::endl << "NO";
		return;
	}

	if((p1 + p2) % 3 == 0)
	{
		std::cout << std::endl << "YES" << std::endl;
	}
}
