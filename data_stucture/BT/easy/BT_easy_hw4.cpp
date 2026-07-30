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

class solution
{
public:
    bool isLeaf(TreeNode *node)
    {
        return node && !node->left && !node->right;
    }
    int sumOfLeftLeaves(TreeNode *root )
    {
        int leftSum {};
        if (!root)
            return 0;

        if (isLeaf(root->left))
            leftSum += root->left->val;

        leftSum += sumOfLeftLeaves (root->left);
        leftSum += sumOfLeftLeaves(root->right);
        
        return leftSum;
    }
};

int main()
{
    BinaryTree tree(3);

    tree.add({9}, {'L'});

    tree.add({20}, {'R'});

    tree.add({20, 15}, {'R', 'L'});

    tree.add({20, 7}, {'R', 'R'});

    cout << solution().sumOfLeftLeaves(tree.root);

    return 0;
}