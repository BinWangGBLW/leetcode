#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *newhead = new ListNode(-1);
        ListNode *p = newhead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return newhead->next;
    }
};

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

int main () {  
  vector <int> a = {1, 3, 5, 7, 9};
  vector <int> b = {2, 4, 6, 8, 10};
  Solution s;
  CreateList c;
  ListNode *l1 = c.create_list(a);
  ListNode *l2 = c.create_list(b);
  c.printlist(l1);
  c.printlist(l2);
  ListNode *root = s.mergeTwoLists(l1, l2);
  c.printlist(root);
  return 0;
}



