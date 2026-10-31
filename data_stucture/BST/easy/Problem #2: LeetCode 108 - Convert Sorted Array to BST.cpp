#include <vector>

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Solution {
private:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        covert(nums, 0, nums.size() - 1);
    }

public:
    TreeNode* covert(std::vector<int>&nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = covert(nums, left, mid - 1);
        root->right = covert(nums, mid + 1, right);
        return root;
    }

};