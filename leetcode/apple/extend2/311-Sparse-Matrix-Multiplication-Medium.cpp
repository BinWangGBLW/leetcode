/*311-Sparse-Matrix-Multiplication-Medium.cpp

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        vector <vector <int>> ans(m, vector <int> (p, 0));
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < p; j++) ans[i][j] += A[i][k] * B[k][j];
            }
        }
        return ans;
    }
};

int main() {
	vector <vector <int>> A = {{1, 0, 0}, {-1, 0, 3}};
	vector <vector <int>> B = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
	Solution s;
	vector<vector<int>> res = s.multiply(A, B);
	for (auto element : res) {
		for (auto n : element)
			cout << n << '\t';
		cout << endl;
	}
	return 0;
}
