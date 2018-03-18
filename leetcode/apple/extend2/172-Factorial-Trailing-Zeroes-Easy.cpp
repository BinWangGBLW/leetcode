#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
这道题并没有什么难度，是让求一个数的阶乘末尾0的个数，
也就是要找乘数中10的个数，而10可分解为2和5，而我们可知2的数量又远大于5的数量，
那么此题即便为找出5的个数。仍需注意的一点就是，像25,125，
这样的不只含有一个5的数字需要考虑进去
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

int main() {
	Solution s;
	int n = 13;
	cout << s.trailingZeroes(n) << endl;
	return 0;
}
