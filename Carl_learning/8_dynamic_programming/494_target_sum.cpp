// 494 target sum
/*
    You are given an integer array nums and an integer target.
    You want to build an expression out of nums by adding one of the 
    symbols '+' and '-' before each integer in nums and then concatenate all the integers.
    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and 
    concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, 
    which evaluates to target. 
    Example 1:
        Input: nums = [1,1,1,1,1], target = 3
        Output: 5
        Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
            -1 + 1 + 1 + 1 + 1 = 3
            +1 - 1 + 1 + 1 + 1 = 3
            +1 + 1 - 1 + 1 + 1 = 3
            +1 + 1 + 1 - 1 + 1 = 3
            +1 + 1 + 1 + 1 - 1 = 3
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum_val = accumulate(nums.begin(), nums.end(), 0);
        if (sum_val < abs(target) || (sum_val + target) % 2 == 1) {
            return 0;
        }
        int newTarget = (sum_val + target) / 2;
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = newTarget; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution sol;
    int res = sol.findTargetSumWays(nums, target);
    cout << res << endl;
    return 0;
}