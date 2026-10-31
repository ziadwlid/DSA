#include <iostream>
using namespace std;
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (val == root->val) return root;
        if (val < root->val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
