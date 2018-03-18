#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Description:

1. Count the number of prime numbers less than a non-negative number, n.
2. and how to print all the primes

*/

class Solution {
public:
    int countPrimes(int n) {
        vector <bool> num(n - 1, true);
        num[0] = false;
        int res = 0, lim = sqrt(n);
        for (int i = 2; i <= lim; ++i) {
            if (num[i - 1]) {
                for (int j = i * i; j < n; j += i) {
                    num[j - 1] = false;
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (num[i]) ++ res;
        }
        return res;
    }
    
    vector <int> collectPrimes(int n) {
        vector <bool> num(n - 1, true);
        vector <int> res;
        num[0] = false;
        int lim = sqrt(n);
        for (int i = 2; i <= lim; ++i) {
            if (num[i - 1]) {
                for (int j = i * i; j < n; j += i) {
                    num[j - 1] = false;
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (num[i]) res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
	Solution s;
	int n = 100;
	vector <int> res;
	cout << "The number of prime in 100 is: " << s.countPrimes(n) << endl;
	res = s.collectPrimes(n);
	cout << "They are:" << endl;
	for (auto n : res)
		cout << n << '\t';
	cout << endl;
	return 0;
}
