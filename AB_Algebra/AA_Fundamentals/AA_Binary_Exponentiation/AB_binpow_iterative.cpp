// AB_binpow_iterative.cpp
/*
 * This file shows the use of binary exponentiation of calculation of power
 * using iterative approach. This gives optimization.
 */
// Date Created: 17 February, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#implementation

#include <iostream>

long long binpow(long long num, long long exp) {
	// num holds the num^(2^index in consideration)
	// num and exp variables are reused in the code but carry different use.
	// The pnemonic meaning is not present in  the code.
	long long res=1ll;
	// while loop continues till all set bits in the exp are taken care of
	while (exp) {
		// result is multiplied by pow if the bit is set
		// this condition is required to check when to multiply.
		if (exp&1ll) { res *= num; }
		// pow is squared and exp is updated to next significant bit.
		num *= num; exp>>=1ll; }
	return res; }

int main(int argc, char**argv) {
	long long num, exp; std::cin >> num >> exp;
	std::cout << binpow(num, exp) << std::endl;
	return 0; }
