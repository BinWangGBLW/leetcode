#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    void print_info(TreeNode* p, TreeNode* q) {
      bool m = isSameTree(p, q);
      if (m) cout << "The two trees are the same tree" << endl;
      else cout << "The two trees are not the same tree" << endl;
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
};


int main() {
  vector <string> a = {"1", "null", "2", "3"};
  vector <string> b = {"1", "null", "2", "3"};
  vector <string> c = {"1", "2", "3"};
  Createtree d;
  TreeNode *roota = d.createTree(a);
  TreeNode *rootb = d.createTree(b);
  TreeNode *rootc = d.createTree(c);
  Solution s;
  s.print_info(roota, rootb);
  s.print_info(roota, rootc);
  return 0;
}
