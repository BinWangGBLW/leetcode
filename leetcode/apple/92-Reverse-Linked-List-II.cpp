#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *result = head;
        int len = n - m + 1;
        ListNode *previous = nullptr;
        while (head && --m) {
            previous = head;
            head = head->next;
        } // this is to covert the pointer head to the m's previous position
        ListNode *tail_keep = head; // keep the head after
        ListNode *newhead = nullptr;
        while (head && len--) {
            ListNode *tmp = head->next;
            head->next = newhead;
            newhead = head;
            head = tmp;
        }
        tail_keep->next = head; // connect the tail after the reverse
        if (previous) 
            previous->next = newhead;
        else
            result = newhead; // since the previous is nullptr, so m == 1. From the first place to reverse.
        return result;
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
  
  vector <int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  Solution s;
  CreateList c;
  ListNode *root = c.create_list(nums);
  c.printlist(root);
  root = s.reverseBetween(root, 2, 5);
  c.printlist(root);
  return 0;
}
