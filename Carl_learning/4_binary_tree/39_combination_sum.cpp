// 39 Combination Sum
/*
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target.
    You may return the combinations in any order. 
    The same number may be chosen from candidates an unlimited number of times.
    Two combinations are unique if the frequency of at least one of the chosen numbers is different. 
    The test cases are generated such that the number of unique combinations that sum up to target 
    is less than 150 combinations for the given input. 
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates, int target, int sum, int start) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) continue;
            path.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
    }
};
int main() 
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}