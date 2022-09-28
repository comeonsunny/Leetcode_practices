// 77 Combinations
/*
    Given two integers n and k, return all possible combinations of k numbers chosen from 1 to n.
    You may return the answer in any order.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, k, 1, path, res);
        return res;
    }
private:
    void dfs(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (auto v : res) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

