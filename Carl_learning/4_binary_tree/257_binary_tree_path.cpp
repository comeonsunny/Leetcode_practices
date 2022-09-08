// 257 binary tree path
/*
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string path = to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
            return res;
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for (auto l : left) {
            res.push_back(path + "->" + l);
        }
        for (auto r : right) {
            res.push_back(path + "->" + r);
        }
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution sol;
    vector<string> res = sol.binaryTreePaths(root);
    for (auto s : res) {
        cout << s << endl;
    }
    return 0;
}