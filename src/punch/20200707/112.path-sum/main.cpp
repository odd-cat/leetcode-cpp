/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            return true;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    TreeNode root(5);
    TreeNode l1_left(4), l1_right(8);
    TreeNode l2_left(11), l2_mid(13), l2_right(4);
    TreeNode l3_left(7), l3_mid(2), l3_right(1);

    l2_left.left = &l3_left;
    l2_left.right = &l3_mid;
    l2_right.right = &l3_right;
    l1_left.left = &l2_left;
    l1_right.left = &l2_mid;
    l1_left.right = &l2_right;

    root.left = &l1_left;
    root.right = &l1_right;

    Solution solu;
    std::cout << solu.hasPathSum(&root, 22) << std::endl;
    return 0;
}