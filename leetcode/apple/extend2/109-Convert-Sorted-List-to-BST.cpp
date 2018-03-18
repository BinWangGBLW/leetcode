#include <iostream>
#include <vector>
#include <algorithm>

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    
    TreeNode *buildTree(ListNode * start, ListNode * end) {
        if (start == end) return nullptr;
        ListNode *slow = start, *fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildTree(start, slow);
        root->right = buildTree(slow->next, end);
        return root;
    }
};

class Createtree {
  public:
 //levelorder traversal
  TreeNode* createTree(vector <string> a)
  {
    int n = (int) a.size();
    vector <TreeNode *> tree (n, nullptr);
    for(int i=0; i<n; i++) {
        if (a[i]== "null" ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(stoi(a[i]));
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        pushorder(root, 0, res);
        return res;
        
    }
  
    void pushorder(TreeNode*root, int level, vector <vector <int>> &res) {
        if (!root) return;
        if ((int)res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) pushorder(root->left, level + 1, res);
        if (root->right) pushorder(root->right, level + 1, res);
    }
  
    void printtree(TreeNode *root) {
      vector <vector <int>> res = levelOrder(root);
      cout << "[" << '\n';
      for(int i = 0; i < (int)res.size(); ++i) {
        cout << "[";
        int j = 0;
        for (j = 0; j < (int)res[i].size() - 1; ++j)
          cout << res[i][j] << ", ";
        cout << res[i][j] << "]\n";
      }
      cout << "]" << '\n';
    }
    void printvec(vector <vector <int>> &res) {
      cout << "[" << '\n';
      for(int i = 0; i < (int)res.size(); ++i) {
        cout << "[";
        int j = 0;
        for (j = 0; j < (int)res[i].size() - 1; ++j)
          cout << res[i][j] << ", ";
        cout << res[i][j] << "]\n";
      }
      cout << "]" << '\n';
    }
};

/* Given the sorted linked list: [-10,-3,0,5,9] */

int main() {
	Solution s;
	ListNode a(-10);
	ListNode b(-3);
	ListNode c(0);
	ListNode d(5);
	ListNode e(9);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	TreeNode *root = s.sortedListToBST(&a);
	Createtree p;
	p.printtree(root);
	return 0;
}
