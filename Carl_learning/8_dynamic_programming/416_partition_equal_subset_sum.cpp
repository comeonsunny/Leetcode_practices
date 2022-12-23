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
        vector<int> dp(target + 1, 0);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
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