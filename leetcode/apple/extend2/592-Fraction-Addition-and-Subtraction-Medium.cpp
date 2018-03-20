/*
Given a string representing an expression of fraction addition and subtraction, 
you need to return the calculation result in string format. 
The final result should be irreducible fraction. If your final result is an integer, say 2, 
you need to change it to the format of fraction 

that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int num = 0, dem = 0, A = 0, B = 1; 
        char c;
        while (is >> num >> c >> dem) {
            A = A * dem + num * B;
            B *= dem;
            int g = abs(gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + "/" + to_string(B);
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};


int main () {
	Solution s;
	string s1 = "-1/2+1/2";
	string s2 = "-1/2+1/2+1/3";
	string s3 = "1/3-1/2";
	string s4 = "5/3+1/3";
	cout << s.fractionAddition(s1) << endl;
	cout << s.fractionAddition(s2) << endl;
	cout << s.fractionAddition(s3) << endl;
	cout << s.fractionAddition(s4) << endl;
}
