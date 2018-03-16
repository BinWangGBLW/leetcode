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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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
  ListNode *node = root->next;
  s.deleteNode(node);
  c.printlist(root);
  return 0;
}
