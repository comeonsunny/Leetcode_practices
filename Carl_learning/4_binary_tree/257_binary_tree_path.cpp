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
private:
    vector<string> res;
    void dfs(TreeNode* root, string path) {
        if (root == nullptr) return;
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
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