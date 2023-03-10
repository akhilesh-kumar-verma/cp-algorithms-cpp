// AD_fibonacci.cpp
/* 
 * This file shows the computation of fibonacci numbers using the matrix
 * exponentiation. The base matrix is raised to n-1 power. The matrix is
 * calculated in logarithmic time.
 */
// Date Created: 20 February, 2023
//       Author: Akhilesh Kumar Verma
//         Link: https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-fibonacci-numbers
#include <vector>
using namespace std;
vector<vector<long long>> operator*=(vector<vector<long long>>&X, vector<vector<long long>>&Y) {
	assert(X.size() and Y.size() and X[0].size() == Y.size());
	vector<vector<long long>> Z(X.size(), vector<long long>(Y[0].size()));
	// for every row in the result
	for (size_t i=0ull; i<X.size(); ++i) {
		// for every column in the result
		for (size_t j=0ll; j<Y[0].size(); ++j) {
			// for every partial product of the cell
			for (size_t k=0; k<Y.size(); ++k) {
				// adding mod here is not working
				Z[i][j]=(X[i][k]*Y[k][j]+Z[i][j]); } } }
	return X=Z; }
vector<vector<long long>> exp(vector<vector<long long>> X, long long exp) {
	assert(X.size() and X.size()==X[0].size());
	// initializing result to identity matrix
	// initially making zero matrix as it is easy to set diag later
	vector<vector<long long>> result(X.size(), vector<long long>(X.size()));
	// setting diag elements to 1 to make identity matrix
	for (size_t i=0; i<X.size(); ++i) { result[i][i]=1ll; }	
	while (exp) {
		// multipling the power of 2 if this bit is set
		if (exp&1ll) { result*=X; }
		// squaring the matrix and shifting the exp
		X*=X; exp>>=1ll; }
	return result; }
int main(int argc, char**argv) {
	int n; cin >> n;
	vector<vector<long long>> matrix{{1ll, 1ll}, {1ll, 0ll}};
	vector<vector<long long>> res;
	// if required we are raising the matrix to power n-1
	if (n>0) { res=exp(matrix, n-1); }
	// returning value accordingly
	cout << (n>0?res[0][0]:0) << endl;
	return 0; }

