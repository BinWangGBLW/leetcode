#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
����Ⲣû��ʲô�Ѷȣ�������һ�����Ľ׳�ĩβ0�ĸ�����
Ҳ����Ҫ�ҳ�����10�ĸ�������10�ɷֽ�Ϊ2��5�������ǿ�֪2��������Զ����5��������
��ô���⼴��Ϊ�ҳ�5�ĸ���������ע���һ����ǣ���25,125��
�����Ĳ�ֻ����һ��5��������Ҫ���ǽ�ȥ
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
