// AF_klengthpaths_count.cpp
/* 
 * This file finds number of paths between any two nodes in a directed graph.
 * The idea is the matrix multiplication of matrices storing number of paths
 * of length n, m is number of paths of length m+n.
 */
// Date Created: 04 March, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#number-of-paths-of-length-k-in-a-graph
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> matmul(vector<vector<long long>> &X, vector<vector<long long>> &Y) {
    vector<vector<long long>> res(X.size(), vector<long long>(Y[0].size()));
    for (size_t i=0; i<X.size(); ++i) {
        for (size_t j=0; j<Y[0].size(); ++j) {
            for (size_t k=0; k<Y.size(); ++k) {
                res[i][j]+=X[i][k]*Y[k][j]; } } }
    return res; }
vector<vector<long long>> power(vector<vector<long long>> &grid, long long k) {
    vector<vector<long long>> res(grid.size(), vector<long long>(grid.size()));
    for (long long idx=0; idx<grid.size(); ++idx) { res[idx][idx]=1ll; }
    while (k) {
        if (k&1ll) { res=matmul(res, grid); }
        grid=matmul(grid, grid); k>>=1; }
    return res; }
int main() {
    long long n, k; cin >> n >> k;
    vector<vector<long long>> grid(n, vector<long long>(n));
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<n; ++j) {
            cin >> grid[i][j]; } } 
    grid=power(grid, k);
    for (size_t i=0; i<n; ++i) {
        for (size_t j=0; j<n; ++j) {
            cout << grid[i][j] << " "; }
        cout << "\r\n"; }
    return 0; }