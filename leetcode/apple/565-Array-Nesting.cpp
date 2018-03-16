#include <iostream>
#include <vector>

/*
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

Example 1:

Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}

Note:

    N is an integer within the range [1, 20,000].
    The elements of A are all distinct.
    Each element of A is an integer within the range [0, N-1].
*/

using namespace std;

class Solution {
public:
int arrayNesting(vector<int>& nums) {
        int n=nums.size(),cur,start,nxt;
        if(n==0) return 0;
        vector<bool> used(n,false);//用来标记是否遍历过
        int res=0;
        for(start=0;start<n;start++){

            if(used[start]==false)//以遍历过的不用遍历
            {
                int cnt=1;
                cur=start;
                nxt=nums[cur];
                while(nxt!=start){//当重复时终止
                cnt++;
                cur=nxt;
                nxt=nums[cur];
                used[cur]=true;
                }
                res=max(res,cnt);
            }

        }
        return res;
    }
};

int main () {  
  Solution s;
  vector <int> A = {5,4,0,3,1,6,2};
  cout << s.arrayNesting(A) << endl;
}



