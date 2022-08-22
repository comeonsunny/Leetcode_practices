// 209 minimum size subarray sum
/*
    Given an array of positive integers nums and a positive integer tartget, 
    return the minimal length of a contiguous subarray [nums1, nums2, ...]
    of which the sum is greater than or equal to target.
    If there is no such subarray, return 0 instead.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        int sum = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            sum += nums[end];
            while (sum >= target) {
                res = min(res, end - start + 1);
                sum -= nums[start++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}