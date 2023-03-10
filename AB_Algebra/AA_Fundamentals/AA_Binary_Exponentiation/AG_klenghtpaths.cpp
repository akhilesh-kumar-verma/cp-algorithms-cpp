// AG_shortest_klengthpath.cpp
/* 
 * Finds shortest path between any two nodes in a directed graph in k steps.
 */
// Date Created: 10 March, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/graph/fixed_length_paths.html#shortest-paths-of-a-fixed-length
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> compute(vector<vector<long long>> &X, vector<vector<long long>> &Y) {
    // initializing with maximum values
    vector<vector<long long>> res(X.size(),
            vector<long long>(Y[0].size()), numeric_limits<long long>::max());
    for (size_t i=0; i<X.size(); ++i) {
        for (size_t j=0; j<Y[0].size(); ++j) {
            for (size_t k=0; k<Y.size(); ++k) {
                // skipping the path if any of segment has max value
                // this is useless and instead leads to overflow.
                if (X[i][k]==numeric_limits<long long>::max() or
                    Y[k][j]==numeric_limits<long long>::max()) { continue; }
                // if new path is shortes then assign it in the result matrix
                if (X[i][k]+Y[k][j]<res[i][j]) {
                        res[i][j]=X[i][k]+Y[k][j]; } } } }
    return res; }
vector<vector<long long>> power(vector<vector<long long>> &grid, long long k) {
    // initializing the matrix with huge values
    vector<vector<long long>> res(grid.size(),
            vector<long long>(grid.size(), numeric_limits<long long>::max()));
    while (k) {
        // update the result matrix as required
        if (k&1ll) { res=compute(res, grid); }
        // finding even shorter paths
        grid=compute(grid, grid); k>>=1; }
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