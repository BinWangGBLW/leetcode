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
    ListNode* reverseList(ListNode* head) {
        return swapnode(head, nullptr);
    }
    ListNode *swapnode(ListNode *head, ListNode *newHead) {
        if (head == nullptr) return newHead;
        ListNode *tmp = head->next;
        head->next = newHead;
        return swapnode(tmp, head);
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
  
  vector <int> nums = {1, 3, 5, 7, 9};
  Solution s;
  CreateList c;
  ListNode *root = c.create_list(nums);
  c.printlist(root);
  root = s.reverseList(root);
  c.printlist(root);
  return 0;
}
