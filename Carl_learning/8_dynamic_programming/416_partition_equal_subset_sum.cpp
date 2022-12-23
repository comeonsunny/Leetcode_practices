// 416. Partition Equal Subset Sum
/*
    Given a non-empty array nums containing 
    only positive integers, find if the array 
    can be partitioned into two subsets such that 
    the sum of elements in both subsets is equal.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        // leverage the backtracking method
        return backtracking(nums, target, 0, 0);
    }
    bool backtracking(vector<int>& nums, int target, int start, int cur_sum) {
        if (cur_sum == target) return true;
        if (cur_sum > target) return false;
        for (int i = start; i < nums.size(); ++i) {
            cur_sum += nums[i];
            if (backtracking(nums, target, i + 1, cur_sum)) return true;
            cur_sum -= nums[i];
        }
        return false;
    }
};
int canPartition_test() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << sol.canPartition(nums) << endl;
    return 0;
}
int main()
{
    canPartition_test();
    return 0;
}