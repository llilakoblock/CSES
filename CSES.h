﻿// CSES.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

class CSES
{
public:
	//Consider an algorithm that takes as input a positive integer n.If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by threeand adds one.The algorithm repeats this, until n is one.For example, the sequence for n = 3 is as follows :
	//3→10→5→16→8→4→2→1

	//	Your task is to simulate the execution of the algorithm for a given value of n.
	//	Input
	//	The only input line contains an integer n.
	//	Output
	//	Print a line that contains all values of n during the algorithm.
	//	Constraints
	//	1≤n≤106
	//	Example
	//	Input :
	//3
	//	Output :
	//	3 10 5 16 8 4 2 1

	std::vector<int64_t>  weird_algorithm(int64_t n);

	//Time limit : 1.00 s Memory limit : 512 MB
	//	You are given all numbers between 1, 2, …, n except one.Your task is to find the missing number.
	//	Input
	//	The first input line contains an integer n.
	//	The second line contains n−1 numbers.Each number is distinctand between 1 and n(inclusive).
	//	Output
	//	Print the missing number.
	//	Constraints
	//	2≤n≤2⋅105
	//	Example
	//	Input :
	//5
	//	2 3 1 5
	//	Output :
	//	4

	std::vector<int64_t> missing_number(int64_t n, std::vector<int64_t> numbers);

	//You are given a DNA sequence : a string consisting of characters A, C, G, and T.Your task is to find the longest repetition in the sequence.This is a maximum - length substring containing only one type of character.

	//	Input
	//	The only input line contains a string of n characters.
	//	Output
	//	Print one integer : the length of the longest repetition.
	//	Constraints
	//	1≤n≤106
	//	Example
	//	Input :
	//ATTCGGGA
	//	Output :
	//3

	int64_t repetition(const std::string& input);

	//You are given an array of n integers.You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

	//	On each move, you may increase the value of any element by one.What is the minimum number of moves required ?
	//	Input
	//	The first input line contains an integer n : the size of the array.
	//	Then, the second line contains n integers x1, x2, …, xn : the contents of the array.
	//	Output
	//	Print the minimum number of moves.
	//	Constraints
	//	1≤n≤2⋅105
	//	1≤xi≤109
	//	Example
	//	Input :
	//5
	//	3 2 5 1 7
	//	Output :
	//	5

	int64_t increasing_array(std::vector<int64_t>& array);

	//A permutation of integers 1, 2, …, n is called beautiful if there are no adjacent elements whose difference is 1.
	//	Given n, construct a beautiful permutation if such a permutation exists.
	//	Input
	//	The only input line contains an integer n.
	//	Output
	//	Print a beautiful permutation of integers 1, 2, …, n.If there are several solutions, you may print any of them.If there are no solutions, print "NO SOLUTION".
	//	Constraints
	//	1≤n≤106
	//	Example 1
	//	Input:
	//5
	//	Output :
	//	4 2 5 3 1
	//	Example 2
	//	Input :
	//	3
	//	Output :
	//	NO SOLUTION

	std::vector<int64_t> permutation_integers(int64_t n);

	//Your task is to count for k = 1, 2, …, n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

	//	Input
	//	The only input line contains an integer n.
	//	Output
	//	Print n integers : the results.
	//	Constraints
	//	1≤n≤10000
	//	Example
	//	Input :
	//8
	//	Output :
	//	0
	//	6
	//	28
	//	96
	//	252
	//	550
	//	1056
	//	1848

	void two_knights(int64_t n);

	//Your task is to divide the numbers 1, 2, …, n into two sets of equal sum.

	//	Input
	//	The only input line contains an integer n.
	//	Output
	//	Print "YES", if the division is possible, and "NO" otherwise.
	//	After this, if the division is possible, print an example of how to create the sets.First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
	//	Constraints
	//	1≤n≤106
	//	Example 1
	//	Input:
	//7
	//	Output :
	//	YES
	//	4
	//	1 2 4 7
	//	3
	//	3 5 6
	//	Example 2
	//	Input:
	//6
	//	Output :
	//	NO

	void two_sets(int64_t n);
};

