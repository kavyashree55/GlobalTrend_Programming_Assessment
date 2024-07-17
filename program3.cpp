#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }

private:
    int maxSum;
    int maxGain(TreeNode* node) {
        if (node == NULL) return 0;

        // max sum on the left and right subtree of node
        int leftGain = std::max(maxGain(node->left), 0);
        int rightGain = std::max(maxGain(node->right), 0);

        // the value of the current node plus maximum path sum of the left and right subtrees
        int priceNewpath = node->val + leftGain + rightGain;

        // update maxSum if it's less than priceNewpath
        maxSum = std::max(maxSum, priceNewpath);

        // return the max gain if the node is added to the path
        return node->val + std::max(leftGain, rightGain);
    }
};

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int maxPathSum = solution.maxPathSum(root);
    std::cout << "Maximum path sum: " << maxPathSum << std::endl;

    return 0;
}


