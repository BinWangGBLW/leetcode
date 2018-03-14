#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition of TreeNode

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Createtree {
  public:
 //levelorder traversal
  TreeNode* createTree(vector <string> a)
  {
    int n = (int) a.size();
    vector <TreeNode *> tree (n, nullptr);
    for(int i=0; i<n; i++) {
        if (a[i]== "#" ){
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
};

int main() {
  vector <string> a = {"1", "#", "3", "2", "3", "#", "#", "4", "5"};
  Createtree t;
  TreeNode *root = t.createTree(a);
  t.printtree(root);
  return 0;
}

