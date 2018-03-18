/*

2. Add Two Numbers I

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *ptr = dummy;
        int current = 0;
        while (l1 || l2) {
            int val = current;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            current = val / 10;
            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
        }
        if (current == 1) ptr->next = new ListNode(1);
        return dummy->next;
    }
};

/*
445. Add Two Numbers II Medium

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <ListNode *> s1, s2;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top()->val;
                s2.pop();
            }
            res->val = sum % 10;
            ListNode * head = new ListNode(sum / 10);
            head ->next = res;
            res = head;
            sum /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};

/*
Create list using vector
*/ 
class CreateList {
  public:
    ListNode* create_list(vector <int> &nums) {
      ListNode *root = new ListNode(0);
      ListNode *ptr = root;
      for (auto num : nums) {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
      }
      return root->next;
    }
    
    void printlist(ListNode *root) {
      ListNode *ptr = root;
      while(ptr) {
        cout << ptr->val << '\t';
        ptr = ptr->next;
      }
      cout << endl;
    }
};

int main() {
	vector <int> a1 = {2, 4, 3};
	vector <int> a2 = {5, 6, 4};
	CreateList C;
	Solution S;
	Solution2 S2;
	ListNode *l1 = C.create_list(a1);
	ListNode *l2 = C.create_list(a2);
	ListNode *res = S.addTwoNumbers(l1, l2);
	ListNode *res2 = S2.addTwoNumbers(l1, l2);
	C.printlist(res);
	C.printlist(res2);
	return 0;
}
