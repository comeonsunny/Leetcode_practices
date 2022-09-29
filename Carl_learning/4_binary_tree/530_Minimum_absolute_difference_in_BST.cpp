// 530. Minimum Absolute Difference in BST
/*
    Given the root of a Binary Search Tree (BST), return the minimum absolute difference 
    between the values of nay two different nodes in the tree.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// class Solution {
// public:
//     int getMinimumDifference(TreeNode* root) {
//         inorder(root);
//         for (int i = 1; i < this->arr.size(); ++i) {
//             this->res = min(res, arr[i] - arr[i - 1]);
//         }
//         return res;
//     }
// private:
//     vector<int> arr;
//     int res = INT_MAX;
//     void inorder(TreeNode* root) {
//         if (!root) return;
//         inorder(root->left);
//         arr.push_back(root->val);
//         inorder(root->right);
//     }
// };
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
private:
    int pre = -1;
    int res = INT_MAX;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (pre == -1) pre = root->val;
        else {
            res = min(res, root->val -pre);
            pre = root->val;
        }
        inorder(root->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    Solution s;
    cout << s.getMinimumDifference(root) << endl;
    return 0;
}