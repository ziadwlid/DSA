//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int val) : val(val)
    {
    }
};

struct BinaryTree
{
    TreeNode *root{};
    BinaryTree(int root_value) : root(new TreeNode(root_value))
    {
    }

    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        TreeNode *current = this->root;
        // iterate on the path, create all necessary TreeNodes
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                else
                    assert(current->left->val == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                else
                    assert(current->right->val == values[i]);
                current = current->right;
            }
        }
    }
    void _PrintInorder(TreeNode *current)
    {
        if (!current)
            return;
        _PrintInorder(current->left);
        cout << current->val << " ";
        _PrintInorder(current->right);
    }
    void printInorder()
    {
        _PrintInorder(root);
        cout << "\n";
    }
};

class hassPathSum
{
public:
    
    bool isLeaf(TreeNode *node)
    {
        return node && !node->left && !node->right;
    }
    bool hasTargetSum(TreeNode *root, int targetSum, int sum = 0)
    {
        if (!root)
            return 0;

        sum += root->val;
        if (isLeaf(root))
            return targetSum == sum;
        return hasTargetSum(root->left, targetSum, sum) || 
        hasTargetSum(root->right, targetSum, sum);
        
    }
};

int main()
{
    BinaryTree tree(5);

    tree.add({4}, {'L'});

    tree.add({8}, {'R'});

    tree.add({4, 11}, {'L', 'L'});

    tree.add({8, 13}, {'R', 'L'});

    tree.add({8, 4}, {'R', 'R'});

    tree.add({4, 11, 7}, {'L', 'L', 'L'});

    tree.add({4, 11, 2}, {'L', 'L', 'R'});

    tree.add({8, 4, 1}, {'R', 'R', 'R'});
	cout << hassPathSum().hasTargetSum(tree.root, 22) << "\n";
    return 0;
}