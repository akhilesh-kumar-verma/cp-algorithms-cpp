// AE_kpermutations.cpp
/*
 * The approach is to use binary exponentiation on the permutation. The nth
 * permutation is permuted according to the same permuation to get the 2nth
 * permutation. This is hard to visualize.
 */
// Date Created: 04 March, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#applying-a-permutation-k-times
#include <iostream>
#include <vector>
using namespace std;
void permute(vector<long long>&sequence, vector<long long> &permuation) {
    // creating the new vector to store the permutation
    vector<long long> newSequence(sequence.size());
    // In the loop the new sequence is made according to the rules
    for (long long idx=0; idx<sequence.size(); ++idx) {
        newSequence[idx]=sequence[permuation[idx]]; }
    // copying the new sequence to the actual sequence
    sequence=newSequence; }
void kpermute(vector<long long>&sequence, vector<long long> &permuation, long long k) {
    while (k) {
        // applying permutation to the sequence
        if (k&1ll) { permute(sequence, permuation); }
        // applying the permutation to itself
        permute(permuation, permuation); k>>=1; } }
int main() {
    long long k, n; cin >> n >> k;
    vector<long long> permuation(n), sequence(n);
    // ith element in permutation is index of the element to apper in that pos
    for (long long idx=0ll; idx<n; ++idx) { cin >> permuation[idx]; }
    for (long long idx=0ll; idx<n; ++idx) { cin >> sequence[idx]; }
    kpermute(sequence, permuation, k);
    for (long long ele: sequence) { cout << ele << " "; } cout << "\r\n" << flush;
    return 0; }