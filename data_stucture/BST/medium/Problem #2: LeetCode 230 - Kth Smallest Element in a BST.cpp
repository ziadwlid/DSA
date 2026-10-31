
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Solution {

public:

    int Smallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorderTraversal(root, k, count, result);
        return result;
    }
    void inorderTraversal(TreeNode* root, int k, int& count, int& result) {
        if (root == nullptr || count >= k)
            return;
        inorderTraversal(root->left, k, count, result);
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorderTraversal(root->right, k, count, result);
    }
};
