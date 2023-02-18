// AC_modular_binpow_iterative.cpp
/*
 * This file shows the iterative version of modular binary exponentiation.
 * The file uses a mod, number to modulo the result each time. The result of
 * any calculation must not go beyond the limits. so the mod must be less than
 * the srqt of max number in long long
 */
// Date Created: 17 February, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number

#include <iostream>

long long binpowmod(long long pow, long long exp, long long mod) {
	pow %= mod;
	long long res = 1ll;
	while (exp) {
		if (exp&1ll) { res=pow*res%mod; }
		pow = pow*pow%mod;
		exp >>= 1ll; }
	return res; }

int main(int argc, char**argv) {
	long long num, exp, mod; std::cin >> num >> exp >> mod;
	std::cout << binpowmod(num, exp, mod) << std::endl;
	return 0; }
