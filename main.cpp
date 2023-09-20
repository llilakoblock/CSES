
#include "CSES.h"
#include <cassert>

using namespace std;

int main()
{
	CSES cses;

	auto res = cses.weird_algorithm(3);
	assert((res) == (std::vector<int64_t>{3, 10, 5, 16, 8, 4, 2, 1}));

	auto res1 = cses.missing_number(5, { 2,3,1,5 });
	assert((res1) == (std::vector<int64_t>{4}));

	auto res2 = cses.repetition("ATTCGGGA");
	assert(res2 == 3);

	std::vector<int64_t> array{ 3,2,5,1,7 };
	auto res3 = cses.increasing_array(array);
	assert(res3 == 5);

	array = std::vector<int64_t> { 2,4,1,3,5 };
	auto res4 = cses.permutation_integers(5);
	assert(res4 == array);

	cses.two_sets(7);

	cses.two_piles(6, 12);

	cses.palindrome_reorder("AAAACACBA");


	return 0;
}

