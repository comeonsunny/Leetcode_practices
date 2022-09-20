// Maximum Binary Tree
/*
    You are given an integer array nums with no duplicates.
    A maximum binary tree can be built recursively from nums using the following algorithm:
    1. Create a root node whose value is the maximum value in nums. 
    2. Recursively build the left substree on the subarray prefix to the left of the maximum value. 
    3. Recursively build the right substree on the subarray suffix to the right of the maximum value. 
    Return the maximum binary tree built from nums. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        int val_max, index_max;
        val_max = nums[0];
        index_max = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > val_max) {
                val_max = nums[i];
                index_max = i;
            }
        }
        TreeNode * root = new TreeNode(val_max);
        if (index_max > 0) {
            std::vector<int> left_subtree(nums.begin(), nums.begin() + index_max);
            root->left = constructMaximumBinaryTree(left_subtree);
        }
        if (index_max < nums.size() - 1) {
            std::vector<int> right_subtree(nums.begin() + index_max + 1, nums.end());
            root->right = constructMaximumBinaryTree(right_subtree);
        }
        return root;
    }
};
void pre_order(TreeNode * root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
int main()
{
    std::vector<int> nums = {3,2,1,6,0,5};
    Solution sol;
    TreeNode * root = sol.constructMaximumBinaryTree(nums);
    pre_order(root);
    return 0;
}