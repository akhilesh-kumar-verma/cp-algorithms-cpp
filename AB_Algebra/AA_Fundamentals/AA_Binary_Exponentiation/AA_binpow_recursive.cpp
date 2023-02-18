// AA_binpow_recursive.cpp
/*
 * This shows a recursive implementation of calculation of power using binary
 * exonentitation.
 */
// Date Created: 17 February, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#implementation

#include <iostream>

long long binpow(long long num, long long exp) {
	if (exp == 0ll) { return 1ll; }
	long long res = binpow(num, exp/2ll);
	// exp&1 is eqt to exp%2
	return exp&1ll ? res*res*num : res*res; }

int main (int argc, char **argv) {
	long long num, exp; std::cin >> num >> exp;
	std::cout << binpow(num, exp) << std::endl;
	return 0; }

