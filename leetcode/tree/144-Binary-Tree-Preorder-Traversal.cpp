#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> res;
        preorder(root, res);
        return res;
    }
    void preorder(TreeNode *root, vector <int> &res) {
        if (!root) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
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
  Createtree c;
  TreeNode *root = c.createTree(a);
  Solution s;
  cout << "The preorder traversal sequence is " << '\n';
  vector <int> pre = s.preorderTraversal(root);
  for (int i = 0; i < (int) pre.size(); ++i) {
    cout << pre[i] << '\t';
  }
  cout << endl;
  return 0;
}


